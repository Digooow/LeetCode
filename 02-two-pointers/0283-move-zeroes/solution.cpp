#include <cassert>
#include <iostream>
#include <utility>
#include <vector>

class Solution {
public:
    void moveZeroes(std::vector<int>& nums) {
        std::size_t nonZeroPos = 0;

        for (std::size_t i = 0; i < nums.size(); ++i) {
            if (nums[i] != 0) {
                std::swap(nums[nonZeroPos], nums[i]);
                ++nonZeroPos;
            }
        }
    }
};

int main() {
    Solution solver;

    std::vector<int> nums1 = {0, 1, 0, 3, 12};
    solver.moveZeroes(nums1);
    assert((nums1 == std::vector<int>{1, 3, 12, 0, 0}));

    std::vector<int> nums2 = {0};
    solver.moveZeroes(nums2);
    assert((nums2 == std::vector<int>{0}));

    std::cout << "[OK] 0283 - Move Zeroes: todos os testes passaram.\n";
    return 0;
}
