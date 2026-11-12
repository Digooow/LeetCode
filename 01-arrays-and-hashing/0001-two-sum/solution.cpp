#include <cassert>
#include <iostream>
#include <unordered_map>
#include <vector>

class Solution {
public:
    std::vector<int> twoSum(const std::vector<int>& nums, int target) {
        std::unordered_map<int, int> seen;
        seen.reserve(nums.size());

        for (int i = 0; i < static_cast<int>(nums.size()); ++i) {
            int complement = target - nums[i];
            auto it = seen.find(complement);
            if (it != seen.end()) {
                return {it->second, i};
            }
            seen[nums[i]] = i;
        }

        return {};
    }
};

int main() {
    Solution solver;

    assert((solver.twoSum({2, 7, 11, 15}, 9) == std::vector<int>{0, 1}));
    assert((solver.twoSum({3, 2, 4}, 6) == std::vector<int>{1, 2}));
    assert((solver.twoSum({3, 3}, 6) == std::vector<int>{0, 1}));

    std::cout << "[OK] 0001 - Two Sum: todos os testes passaram.\n";
    return 0;
}
