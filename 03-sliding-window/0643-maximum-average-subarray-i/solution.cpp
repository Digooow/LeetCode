#include <algorithm>
#include <cassert>
#include <cmath>
#include <iostream>
#include <vector>

class Solution {
public:
    double findMaxAverage(const std::vector<int>& nums, int k) {
        long long windowSum = 0;
        for (int i = 0; i < k; ++i) {
            windowSum += nums[i];
        }

        long long maxSum = windowSum;
        for (int i = k; i < static_cast<int>(nums.size()); ++i) {
            windowSum += nums[i] - nums[i - k];
            maxSum = std::max(maxSum, windowSum);
        }

        return static_cast<double>(maxSum) / k;
    }
};

int main() {
    Solution solver;

    assert(std::abs(solver.findMaxAverage({1, 12, -5, -6, 50, 3}, 4) - 12.75) < 1e-5);
    assert(std::abs(solver.findMaxAverage({5}, 1) - 5.0) < 1e-5);

    std::cout << "[OK] 0643 - Maximum Average Subarray I: todos os testes passaram.\n";
    return 0;
}
