#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>

// 定义语法分析树节点
class TreeNode {
public:
    std::string data;
    std::vector<TreeNode*> children;

    TreeNode(const std::string& d) : data(d) {}
    ~TreeNode() {
        for (auto child : children) {
            delete child;
        }
    }
};

// 语法分析器类
class Parser {
private:
    std::ifstream grammarFile;
    std::vector<std::string> nonTerminals;
    std::vector<std::string> terminals;
    std::vector<std::string> productions;

    bool isTerminal(const std::string& symbol) const {
        return std::find(terminals.begin(), terminals.end(), symbol) != terminals.end();
    }

    TreeNode* parseProduction(const std::string& nonTerminal, const std::vector<std::string>& tokens) {
        std::string line;
        while (std::getline(grammarFile, line)) {
            if (line.empty() || line[0] == '#') {
                continue;
            }
            std::istringstream iss(line);
            std::string lhs, arrow, rhs;
            iss >> lhs >> arrow >> rhs;
            if (lhs == nonTerminal && arrow == "->") {
                TreeNode* node = new TreeNode(lhs);
                std::istringstream rhsStream(rhs);
                std::string symbol;
                while (rhsStream >> symbol) {
                    if (symbol != "|") {
                        if (isTerminal(symbol) || symbol == "EPSILON") {
                            node->children.push_back(new TreeNode(symbol));
                        } else {
                            // 如果是非终结符，则递归地解析该非终结符的产生式
                            TreeNode* child = parseProduction(symbol, tokens);
                            if (child) {
                                node->children.push_back(child);
                            }
                        }
                    }
                }
                return node;
            }
        }
        return nullptr;
    }

public:
    Parser(const std::string& grammarFilename) {
        grammarFile.open(grammarFilename);
        if (!grammarFile.is_open()) {
            std::cerr << "Error opening grammar file!" << std::endl;
            exit(EXIT_FAILURE);
        }
        std::string line;
        while (std::getline(grammarFile, line)) {
            if (line.empty() || line[0] == '#') {
                continue;
            }
            std::istringstream iss(line);
            std::string lhs, arrow, rhs;
            iss >> lhs >> arrow >> rhs;
            if (arrow == "->") {
                nonTerminals.push_back(lhs);
                std::istringstream rhsStream(rhs);
                std::string symbol;
                while (rhsStream >> symbol) {
                    if (symbol != "|") {
                        productions.push_back(symbol);
                    }
                }
            } else {
                terminals.push_back(lhs);
            }
        }
        grammarFile.clear();
        grammarFile.seekg(0, std::ios::beg);
    }

    ~Parser() {
        grammarFile.close();
    }

    TreeNode* parse(const std::string& startSymbol, const std::vector<std::string>& tokens) {
        grammarFile.clear();
        grammarFile.seekg(0, std::ios::beg);
        return parseProduction(startSymbol, tokens);
    }
};

int main() {
    Parser parser("grammar.txt");

    std::vector<std::string> tokens = {"The", "man", "chased", "the", "dog", "with", "a", "stick"};
    TreeNode* syntaxTree = parser.parse("S", tokens);

    std::cout << "Syntax Tree:" << std::endl;
    std::cout << syntaxTree->data << std::endl;
    for (TreeNode* child : syntaxTree->children) {
        std::cout << "  " << child->data << std::endl;
        for (TreeNode* subChild : child->children) {
            std::cout << "    " << subChild->data << std::endl;
        }
    }

    delete syntaxTree;
    return 0;
}
