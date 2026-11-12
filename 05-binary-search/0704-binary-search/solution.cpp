#include <cassert>
#include <iostream>
#include <vector>

class Solution {
public:
    int search(const std::vector<int>& nums, int target) {
        int left = 0;
        int right = static_cast<int>(nums.size()) - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                return mid;
            }
            if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return -1;
    }
};

int main() {
    Solution solver;

    assert(solver.search({-1, 0, 3, 5, 9, 12}, 9) == 4);
    assert(solver.search({-1, 0, 3, 5, 9, 12}, 2) == -1);

    std::cout << "[OK] 0704 - Binary Search: todos os testes passaram.\n";
    return 0;
}
