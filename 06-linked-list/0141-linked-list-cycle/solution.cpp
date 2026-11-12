#include <cassert>
#include <iostream>

struct ListNode {
    int val;
    ListNode* next;
    explicit ListNode(int x, ListNode* n = nullptr) : val(x), next(n) {}
};

class Solution {
public:
    bool hasCycle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                return true;
            }
        }

        return false;
    }
};

int main() {
    auto* n1 = new ListNode(3);
    auto* n2 = new ListNode(2);
    auto* n3 = new ListNode(0);
    auto* n4 = new ListNode(-4);
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n2; // ciclo de volta para n2

    Solution solver;
    assert(solver.hasCycle(n1) == true);

    n4->next = nullptr;
    assert(solver.hasCycle(n1) == false);

    delete n4;
    delete n3;
    delete n2;
    delete n1;

    std::cout << "[OK] 0141 - Linked List Cycle: todos os testes passaram.\n";
    return 0;
}
