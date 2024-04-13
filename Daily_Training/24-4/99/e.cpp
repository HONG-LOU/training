/**
 *    author:  HONG-LOU
 *    created: 2024-04-09 20:44:34
**/
#include <bits/stdc++.h>

struct TreeNode {
    char val;
    std::vector<TreeNode*> children;
    TreeNode(char x) : val(x) {}
};

// 插入节点
void insert(TreeNode* root, std::string s, int pos) {
  bool ok = false;

  if (pos == s.length()) {
    return;
  }

  for (auto child : root -> children) {
    if (child->val == s[pos]) {
      ok = true;
      insert(child, s, pos + 1);
    }
  }

  if (!ok) {
    TreeNode* child = new TreeNode(s[pos]);
    insert(child, s, pos + 1);
    root->children.push_back(child);
  }

}

int ans = 0;

void preorder(TreeNode* root) {
    ans++;
    if (root == nullptr) {
      return;
    }
        
    // cout << root->val << " ";
    for (auto child : root->children) {
        preorder(child);
    }
}

int main() {
    TreeNode* root = new TreeNode('*');
    
    // std::ifstream in;
    // in.open("word.in");

    std::string s;

    while (std::cin >> s) {
      // std::cout << s << "\n";
      insert(root, s, 0);
    }

    preorder(root);

    std::cout << ans << "\n";

    // in.close();

    return 0;
}
