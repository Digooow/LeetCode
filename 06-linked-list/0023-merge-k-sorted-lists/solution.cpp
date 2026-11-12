#include <cassert>
#include <iostream>
#include <queue>
#include <vector>

struct ListNode {
    int val;
    ListNode* next;
    explicit ListNode(int x, ListNode* n = nullptr) : val(x), next(n) {}
};

class Solution {
    struct MinNodeCompare {
        bool operator()(const ListNode* a, const ListNode* b) const {
            return a->val > b->val;
        }
    };

public:
    ListNode* mergeKLists(const std::vector<ListNode*>& lists) {
        std::priority_queue<ListNode*, std::vector<ListNode*>, MinNodeCompare> minHeap;

        for (ListNode* head : lists) {
            if (head != nullptr) {
                minHeap.push(head);
            }
        }

        ListNode dummy(0);
        ListNode* tail = &dummy;

        while (!minHeap.empty()) {
            ListNode* smallest = minHeap.top();
            minHeap.pop();

            tail->next = smallest;
            tail = tail->next;

            if (smallest->next != nullptr) {
                minHeap.push(smallest->next);
            }
        }

        return dummy.next;
    }
};

int main() {
    auto* l1 = new ListNode(1, new ListNode(4, new ListNode(5)));
    auto* l2 = new ListNode(1, new ListNode(3, new ListNode(4)));
    auto* l3 = new ListNode(2, new ListNode(6));

    Solution solver;
    ListNode* merged = solver.mergeKLists({l1, l2, l3});

    std::vector<int> result;
    while (merged != nullptr) {
        result.push_back(merged->val);
        ListNode* tmp = merged;
        merged = merged->next;
        delete tmp;
    }

    assert((result == std::vector<int>{1, 1, 2, 3, 4, 4, 5, 6}));
    std::cout << "[OK] 0023 - Merge k Sorted Lists: todos os testes passaram.\n";
    return 0;
}
