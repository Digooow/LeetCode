#include <cassert>
#include <iostream>
#include <unordered_set>
#include <vector>

class Solution {
public:
    bool containsDuplicate(const std::vector<int>& nums) {
        std::unordered_set<int> seen;
        seen.reserve(nums.size());

        for (int num : nums) {
            if (!seen.insert(num).second) {
                return true;
            }
        }
        return false;
    }
};

int main() {
    Solution solver;

    assert(solver.containsDuplicate({1, 2, 3, 1}) == true);
    assert(solver.containsDuplicate({1, 2, 3, 4}) == false);
    assert(solver.containsDuplicate({1, 1, 1, 3, 3, 4, 3, 2, 4, 2}) == true);

    std::cout << "[OK] 0217 - Contains Duplicate: todos os testes passaram.\n";
    return 0;
}
