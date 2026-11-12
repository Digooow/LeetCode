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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode dummy(0);
        ListNode* tail = &dummy;

        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val <= list2->val) {
                tail->next = list1;
                list1 = list1->next;
            } else {
                tail->next = list2;
                list2 = list2->next;
            }
            tail = tail->next;
        }

        tail->next = (list1 != nullptr) ? list1 : list2;
        return dummy.next;
    }
};

int main() {
    auto* a = new ListNode(1, new ListNode(2, new ListNode(4)));
    auto* b = new ListNode(1, new ListNode(3, new ListNode(4)));

    Solution solver;
    ListNode* merged = solver.mergeTwoLists(a, b);

    std::vector<int> out;
    while (merged != nullptr) {
        out.push_back(merged->val);
        ListNode* tmp = merged;
        merged = merged->next;
        delete tmp;
    }

    assert((out == std::vector<int>{1, 1, 2, 3, 4, 4}));
    std::cout << "[OK] 0021 - Merge Two Sorted Lists: todos os testes passaram.\n";
    return 0;
}
