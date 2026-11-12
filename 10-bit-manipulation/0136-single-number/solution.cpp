#include <cassert>
#include <iostream>
#include <vector>

class Solution {
public:
    int singleNumber(const std::vector<int>& nums) {
        int xorSum = 0;
        for (int num : nums) {
            xorSum ^= num;
        }
        return xorSum;
    }
};

int main() {
    Solution solver;

    assert(solver.singleNumber({2, 2, 1}) == 1);
    assert(solver.singleNumber({4, 1, 2, 1, 2}) == 4);
    assert(solver.singleNumber({1}) == 1);

    std::cout << "[OK] 0136 - Single Number: todos os testes passaram.\n";
    return 0;
}
