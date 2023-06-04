#include "Huffman.h"
Huffman::Huffman() {}
Huffman::~Huffman() {}
void Huffman::compress(std::istream& is, std::ostream& os) {
    // 统计输入流中每个字节出现的次数
    std::unordered_map<uint8_t, uint32_t> frequencyTable;
    uint8_t byte;
    while (is.read(reinterpret_cast<char*>(&byte), 1)) {
        if (frequencyTable.find(byte) == frequencyTable.end()) {
            frequencyTable[byte] = 0;
        }
        frequencyTable[byte]++;
    }
    // 构建哈夫曼树和编码表
    Node* root = buildTree(frequencyTable);
    std::unordered_map<uint8_t, std::vector<bool>> codeTable;
    std::vector<bool> code;
    buildCodeTable(root, code, codeTable);
    // 写入编码表到输出流中
    uint16_t tableSize = static_cast<uint16_t>(codeTable.size());
    os.write(reinterpret_cast<char*>(&tableSize), sizeof(tableSize));
    for (const auto& pair : codeTable) {
        os.write(reinterpret_cast<const char*>(&pair.first), sizeof(pair.first));
        uint8_t codeSize = static_cast<uint8_t>(pair.second.size());
        os.write(reinterpret_cast<const char*>(&codeSize), sizeof(codeSize));
        BitStream bitStream(os);
        for (bool bit : pair.second) {
            bitStream.writeBit(bit);
        }
    }
    // 写入编码后的数据到输出流中
    is.clear();
    is.seekg(0);
    BitStream bitStream(os);
    while (is.read(reinterpret_cast<char*>(&byte), 1)) {
        const std::vector<bool>& code = codeTable[byte];
        for (bool bit : code) {
            bitStream.writeBit(bit);
        }
    }
    bitStream.flush();
    // 释放哈夫曼树的内存
    deleteTree(root);
}
void Huffman::decompress(std::istream& is, std::ostream& os) {
    // 从输入流中读取编码表
    uint16_t tableSize;
    is.read(reinterpret_cast<char*>(&tableSize), sizeof(tableSize));
    std::unordered_map<uint8_t, std::vector<bool>> codeTable;
    for (uint16_t i = 0; i < tableSize; i++) {
        uint8_t symbol;
        is.read(reinterpret_cast<char*>(&symbol), sizeof(symbol));
        uint8_t codeSize;
        is.read(reinterpret_cast<char*>(&codeSize), sizeof(codeSize));
        std::vector<bool> code(codeSize);
        BitStream bitStream(is);
        for (uint8_t j = 0; j < codeSize; j++) {
            code[j] = bitStream.readBit();
        }
        codeTable[symbol] = code;
    }
    // 构建解码表和哈夫曼树
    std::unordered_map<std::vector<bool>, uint8_t> decodeTable;
    for (const auto& pair : codeTable) {
        decodeTable[pair.second] = pair.first;
    }
    Node* root = buildTree(codeTable);
    // 解码数据并写入输出流中
    Node* node = root;
    BitStream bitStream(is);
    uint8_t bit;
    while (is.good()) {
        bit = bitStream.readBit();
        if (bit == 0) {
            node = node->left_;
        } else {
            node = node->right_;
        }
        if (node->left_ == nullptr && node->right_ == nullptr) {
            os.write(reinterpret_cast<const char*>(&node->symbol_), sizeof(node->symbol_));
            node = root;
        }
    }
    // 释放哈夫曼树的内存
    deleteTree(root);
}
Huffman::Node::Node(uint8_t symbol, uint32_t frequency) : symbol_(symbol), frequency_(frequency), left_(nullptr), right_(nullptr) {}
Huffman::Node::Node(uint32_t frequency, Node* left, Node* right) : symbol_(0), frequency_(frequency), left_(left), right_(right) {}
Huffman::Node::~Node() {
    delete left_;
    delete right_;
}
bool Huffman::NodeCompare::operator()(const Node* node1, const Node* node2) const {
    return node1->frequency_ > node2->frequency_;
}
Huffman::Node* Huffman::buildTree(std::unordered_map<uint8_t, uint32_t>& frequencyTable) {
    std::vector<Node*> nodes;
    for (const auto& pair : frequencyTable) {
        nodes.push_back(new Node(pair.first, pair.second));
    }
    std::make_heap(nodes.begin(), nodes.end(), NodeCompare());
    while (nodes.size() > 1) {
        Node* left = nodes.front();
        std::pop_heap(nodes.begin(), nodes.end(), NodeCompare());
        nodes.pop_back();
        Node* right = nodes.front();
        std::pop_heap(nodes.begin(), nodes.end(), NodeCompare());
        nodes.pop_back();
        Node* parent = new Node(left->frequency_ + right->frequency_, left, right);
        nodes.push_back(parent);
        std::push_heap(nodes.begin(), nodes.end(), NodeCompare());
    }
    Node* root = nodes.front();
    nodes.clear();
    return root;
}
void Huffman::buildCodeTable(Node* node, std::vector<bool>& code, std::unordered_map<uint8_t, std::vector<bool>>& codeTable) {
    if (node == nullptr) {
        return;
    }
    if (node->left_ == nullptr && node->right_ == nullptr) {
        codeTable[node->symbol_] = code;
    }
    code.push_back(false);
    buildCodeTable(node->left_, code, codeTable);
    code.pop_back();
    code.push_back(true);
    buildCodeTable(node->right_, code, codeTable);
    code.pop_back();
}
void Huffman::deleteTree(Node* node) {
    if (node == nullptr) {
        return;
    }
    deleteTree(node->left_);
    deleteTree(node->right_);
    delete node;
}