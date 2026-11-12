#include <algorithm>
#include <cassert>
#include <iostream>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    explicit TreeNode(int x, TreeNode* l = nullptr, TreeNode* r = nullptr)
        : val(x), left(l), right(r) {}
};

class Solution {
    int heightAndUpdate(TreeNode* node, int& maxDiameter) {
        if (node == nullptr) {
            return 0;
        }
        int leftHeight = heightAndUpdate(node->left, maxDiameter);
        int rightHeight = heightAndUpdate(node->right, maxDiameter);
        maxDiameter = std::max(maxDiameter, leftHeight + rightHeight);
        return 1 + std::max(leftHeight, rightHeight);
    }

public:
    int diameterOfBinaryTree(TreeNode* root) {
        int maxDiameter = 0;
        heightAndUpdate(root, maxDiameter);
        return maxDiameter;
    }
};

void deleteTree(TreeNode* root) {
    if (root == nullptr) return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

int main() {
    auto* root = new TreeNode(1,
        new TreeNode(2, new TreeNode(4), new TreeNode(5)),
        new TreeNode(3));

    Solution solver;
    assert(solver.diameterOfBinaryTree(root) == 3);

    deleteTree(root);
    std::cout << "[OK] 0543 - Diameter of Binary Tree: todos os testes passaram.\n";
    return 0;
}
