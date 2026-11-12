#include <cassert>
#include <iostream>
#include <vector>

struct ListNode {
    int val;
    ListNode* next;
    explicit ListNode(int x, ListNode* n = nullptr) : val(x), next(n) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;

        while (curr != nullptr) {
            ListNode* nextTemp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextTemp;
        }

        return prev;
    }
};

int main() {
    auto* n3 = new ListNode(3);
    auto* n2 = new ListNode(2, n3);
    auto* n1 = new ListNode(1, n2);

    Solution solver;
    ListNode* rev = solver.reverseList(n1);

    std::vector<int> values;
    while (rev != nullptr) {
        values.push_back(rev->val);
        ListNode* toDelete = rev;
        rev = rev->next;
        delete toDelete;
    }

    assert((values == std::vector<int>{3, 2, 1}));
    std::cout << "[OK] 0206 - Reverse Linked List: todos os testes passaram.\n";
    return 0;
}
