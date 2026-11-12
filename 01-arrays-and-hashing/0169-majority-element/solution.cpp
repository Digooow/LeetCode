#include <cassert>
#include <iostream>
#include <vector>

class Solution {
public:
    int majorityElement(const std::vector<int>& nums) {
        int candidate = 0;
        int count = 0;

        for (int num : nums) {
            if (count == 0) {
                candidate = num;
            }
            count += (num == candidate) ? 1 : -1;
        }

        return candidate;
    }
};

int main() {
    Solution solver;

    assert(solver.majorityElement({3, 2, 3}) == 3);
    assert(solver.majorityElement({2, 2, 1, 1, 1, 2, 2}) == 2);

    std::cout << "[OK] 0169 - Majority Element: todos os testes passaram.\n";
    return 0;
}
