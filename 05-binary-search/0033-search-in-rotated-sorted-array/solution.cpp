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

            if (nums[left] <= nums[mid]) {
                if (nums[left] <= target && target < nums[mid]) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            } else {
                if (nums[mid] < target && target <= nums[right]) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
        }

        return -1;
    }
};

int main() {
    Solution solver;

    assert(solver.search({4, 5, 6, 7, 0, 1, 2}, 0) == 4);
    assert(solver.search({4, 5, 6, 7, 0, 1, 2}, 3) == -1);
    assert(solver.search({1}, 0) == -1);

    std::cout << "[OK] 0033 - Search in Rotated Sorted Array: todos os testes passaram.\n";
    return 0;
}
