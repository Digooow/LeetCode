#include <cassert>
#include <iostream>
#include <vector>

class Solution {
public:
    int searchInsert(const std::vector<int>& nums, int target) {
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

        return left;
    }
};

int main() {
    Solution solver;

    assert(solver.searchInsert({1, 3, 5, 6}, 5) == 2);
    assert(solver.searchInsert({1, 3, 5, 6}, 2) == 1);
    assert(solver.searchInsert({1, 3, 5, 6}, 7) == 4);

    std::cout << "[OK] 0035 - Search Insert Position: todos os testes passaram.\n";
    return 0;
}
