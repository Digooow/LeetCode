#include <cassert>
#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<int> productExceptSelf(const std::vector<int>& nums) {
        const int n = static_cast<int>(nums.size());
        std::vector<int> answer(n, 1);

        int prefix = 1;
        for (int i = 0; i < n; ++i) {
            answer[i] = prefix;
            prefix *= nums[i];
        }

        int suffix = 1;
        for (int i = n - 1; i >= 0; --i) {
            answer[i] *= suffix;
            suffix *= nums[i];
        }

        return answer;
    }
};

int main() {
    Solution solver;

    assert((solver.productExceptSelf({1, 2, 3, 4}) == std::vector<int>{24, 12, 8, 6}));
    assert((solver.productExceptSelf({-1, 1, 0, -3, 3}) == std::vector<int>{0, 0, 9, 0, 0}));

    std::cout << "[OK] 0238 - Product of Array Except Self: todos os testes passaram.\n";
    return 0;
}
