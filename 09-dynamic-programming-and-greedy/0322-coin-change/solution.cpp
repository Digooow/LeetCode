#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

class Solution {
public:
    int coinChange(const std::vector<int>& coins, int amount) {
        const int inf = amount + 1;
        std::vector<int> dp(amount + 1, inf);
        dp[0] = 0;

        for (int curr = 1; curr <= amount; ++curr) {
            for (int coin : coins) {
                if (coin <= curr) {
                    dp[curr] = std::min(dp[curr], 1 + dp[curr - coin]);
                }
            }
        }

        return dp[amount] > amount ? -1 : dp[amount];
    }
};

int main() {
    Solution solver;

    assert(solver.coinChange({1, 2, 5}, 11) == 3);
    assert(solver.coinChange({2}, 3) == -1);
    assert(solver.coinChange({1}, 0) == 0);
    assert(solver.coinChange({1, 3, 4}, 6) == 2);

    std::cout << "[OK] 0322 - Coin Change: todos os testes passaram.\n";
    return 0;
}
