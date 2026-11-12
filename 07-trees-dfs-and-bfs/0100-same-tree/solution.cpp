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
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == nullptr && q == nullptr) {
            return true;
        }
        if (p == nullptr || q == nullptr || p->val != q->val) {
            return false;
        }
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};

void deleteTree(TreeNode* root) {
    if (root == nullptr) return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

int main() {
    auto* t1 = new TreeNode(1, new TreeNode(2), new TreeNode(3));
    auto* t2 = new TreeNode(1, new TreeNode(2), new TreeNode(3));
    auto* t3 = new TreeNode(1, new TreeNode(2), nullptr);

    Solution solver;
    assert(solver.isSameTree(t1, t2) == true);
    assert(solver.isSameTree(t1, t3) == false);

    deleteTree(t1);
    deleteTree(t2);
    deleteTree(t3);
    std::cout << "[OK] 0100 - Same Tree: todos os testes passaram.\n";
    return 0;
}
