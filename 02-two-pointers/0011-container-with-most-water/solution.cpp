#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

class Solution {
public:
    int maxArea(const std::vector<int>& height) {
        int left = 0;
        int right = static_cast<int>(height.size()) - 1;
        int best = 0;

        while (left < right) {
            int width = right - left;
            int minHeight = std::min(height[left], height[right]);
            best = std::max(best, width * minHeight);

            if (height[left] < height[right]) {
                ++left;
            } else {
                --right;
            }
        }

        return best;
    }
};

int main() {
    Solution solver;

    assert(solver.maxArea({1, 8, 6, 2, 5, 4, 8, 3, 7}) == 49);
    assert(solver.maxArea({1, 1}) == 1);

    std::cout << "[OK] 0011 - Container With Most Water: todos os testes passaram.\n";
    return 0;
}
