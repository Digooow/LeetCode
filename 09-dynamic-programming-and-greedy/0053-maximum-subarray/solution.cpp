#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

class Solution {
public:
    int maxSubArray(const std::vector<int>& nums) {
        int currentSum = nums[0];
        int maxSum = nums[0];

        for (std::size_t i = 1; i < nums.size(); ++i) {
            currentSum = std::max(nums[i], currentSum + nums[i]);
            maxSum = std::max(maxSum, currentSum);
        }

        return maxSum;
    }
};

int main() {
    Solution solver;

    assert(solver.maxSubArray({-2, 1, -3, 4, -1, 2, 1, -5, 4}) == 6);
    assert(solver.maxSubArray({1}) == 1);
    assert(solver.maxSubArray({5, 4, -1, 7, 8}) == 23);

    std::cout << "[OK] 0053 - Maximum Subarray: todos os testes passaram.\n";
    return 0;
}
