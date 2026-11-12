#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

class Solution {
public:
    int trap(const std::vector<int>& height) {
        int left = 0;
        int right = static_cast<int>(height.size()) - 1;
        int leftMax = 0;
        int rightMax = 0;
        int totalWater = 0;

        while (left < right) {
            if (height[left] <= height[right]) {
                leftMax = std::max(leftMax, height[left]);
                totalWater += leftMax - height[left];
                ++left;
            } else {
                rightMax = std::max(rightMax, height[right]);
                totalWater += rightMax - height[right];
                --right;
            }
        }

        return totalWater;
    }
};

int main() {
    Solution solver;

    assert(solver.trap({0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1}) == 6);
    assert(solver.trap({4, 2, 0, 3, 2, 5}) == 9);

    std::cout << "[OK] 0042 - Trapping Rain Water: todos os testes passaram.\n";
    return 0;
}
