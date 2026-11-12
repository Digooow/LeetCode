#include <cassert>
#include <iostream>
#include <utility>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    explicit TreeNode(int x, TreeNode* l = nullptr, TreeNode* r = nullptr)
        : val(x), left(l), right(r) {}
};

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr) {
            return nullptr;
        }

        std::swap(root->left, root->right);
        invertTree(root->left);
        invertTree(root->right);
        return root;
    }
};

void deleteTree(TreeNode* root) {
    if (root == nullptr) return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

int main() {
    auto* root = new TreeNode(4,
        new TreeNode(2, new TreeNode(1), new TreeNode(3)),
        new TreeNode(7, new TreeNode(6), new TreeNode(9)));

    Solution solver;
    root = solver.invertTree(root);

    assert(root->left->val == 7);
    assert(root->right->val == 2);
    assert(root->left->left->val == 9);
    assert(root->right->right->val == 1);

    deleteTree(root);
    std::cout << "[OK] 0226 - Invert Binary Tree: todos os testes passaram.\n";
    return 0;
}
