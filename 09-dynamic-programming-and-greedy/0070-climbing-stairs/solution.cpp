#include <cassert>
#include <iostream>

class Solution {
public:
    int climbStairs(int n) {
        if (n <= 2) {
            return n;
        }

        int prev2 = 1;
        int prev1 = 2;

        for (int step = 3; step <= n; ++step) {
            int current = prev1 + prev2;
            prev2 = prev1;
            prev1 = current;
        }

        return prev1;
    }
};

int main() {
    Solution solver;

    assert(solver.climbStairs(2) == 2);
    assert(solver.climbStairs(3) == 3);
    assert(solver.climbStairs(5) == 8);

    std::cout << "[OK] 0070 - Climbing Stairs: todos os testes passaram.\n";
    return 0;
}
