/**
 *    author:  HONG-LOU
 *    created: 2024-04-13 19:03:00
**/
#include <bits/stdc++.h>
#include "gmenu.h"
#include "readG.h"
// #include "deduce.h"

struct TreeNode {
  std::string val;
  std::vector<TreeNode*> children;
  TreeNode(std::string x) : val(x) {}
};

int pos = 0;

void insert(TreeNode* root, std::deque<std::pair<std::string, std::string>> q) {

  if (root->val == q[pos].first) {
    for (auto ch : q[pos].second) {
      std::string cch = "";
      cch += ch;
      TreeNode* child = new TreeNode(cch);
      if (ch >= 'A' && ch <= 'Z'){
        pos++;
        insert(child, q);
      }
      root->children.push_back(child);
    }
  }
}

std::string pre_s = "";

void preorder(TreeNode* root) {
    if (root == nullptr) {
      return;
    }
        
    pre_s += root->val + " ";
    for (auto child : root->children) {
        preorder(child);
    }
}

void printMTree(const std::string& prefix, TreeNode* node, bool isFirst) {
  if (node != nullptr) {
    std::cout << prefix;
    std::cout << (isFirst ? "|---" : ">---" );
    // isFirst = false;

    std::cout << node->val << std::endl;

    for (int i = 0; i < node->children.size(); i++) {
      printMTree( prefix + (isFirst ? "|   " : "    "), node->children[i], i == 0);
    }
  }
}

auto main () -> int {

  read r;

  WG w;

  std::string sentence;

  while (true) {
    int c = choice();
    if (c == -1 || c == 0) {
      shows("Error Input.");
      continue;
    }
    else if (c == 1) {
      w = r.read_grammar();
    }
    else if (c == 2) {
      w.cal_terminal();
      w.cal_non_terminal();
    }
    else if (c == 3) {
      w.split_grammar();
    }
    else if (c == 4) {
      w.cycle_check();
    }
    else if (c == 5) {
      w.print_grammar();
    }
    else if (c == 6) {
      sentence = r.read_sentence();
    }
    else if (c == 7 || c == 8) {
      auto ans = w.deduce(sentence);
      if (ans.get_f().empty()) {
        shows("It is not possible to derive.");
        continue;
      }
      auto td = ans.get_f();
      auto tr = ans.get_s();
      if (c == 7) {
        shows("The derivation process is as follows.");
        std::string wp = "";
        for (auto s : td) {
          wp += "[";
          wp += s;
          wp += "]";
          if (s != td.back()) {
            wp += "=>";
          }
        }
        shows(wp);
      }
      else {
        std::string derive = "";
        for (auto c : tr) {
          derive += "[" + c.first + "->" + c.second + "]";
          if (c != tr.back()) {
            derive += "->";
          }
        }
        std::string tree_s = "";
        shows("Replacement process as follows.");
        shows(derive);
        TreeNode* root = new TreeNode(tr[0].first);
        pos = 0;
        insert(root, tr);
        pre_s = "";
        preorder(root);
        shows("prior order traversal as follow.");
        shows(pre_s);
        shows("Synax Tree as follow.");
        printMTree("", root, false);
        std::cout << "\n";
      }
    }
    else if (c == 9) {
      shows("Bye Bye.");
      break;
    }
  }
  
  return 0;
}