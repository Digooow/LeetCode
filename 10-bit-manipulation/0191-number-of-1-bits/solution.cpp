#include <cassert>
#include <cstdint>
#include <iostream>

class Solution {
public:
    int hammingWeight(std::uint32_t n) {
        int count = 0;
        while (n != 0) {
            n &= (n - 1);
            ++count;
        }
        return count;
    }
};

int main() {
    Solution solver;

    assert(solver.hammingWeight(11) == 3);       // 1011_2
    assert(solver.hammingWeight(128) == 1);      // 10000000_2
    assert(solver.hammingWeight(2147483645) == 30);

    std::cout << "[OK] 0191 - Number of 1 Bits: todos os testes passaram.\n";
    return 0;
}
