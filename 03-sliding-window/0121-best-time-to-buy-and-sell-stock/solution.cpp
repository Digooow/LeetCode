#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

class Solution {
public:
    int maxProfit(const std::vector<int>& prices) {
        if (prices.empty()) {
            return 0;
        }

        int minPrice = prices[0];
        int bestProfit = 0;

        for (int price : prices) {
            minPrice = std::min(minPrice, price);
            bestProfit = std::max(bestProfit, price - minPrice);
        }

        return bestProfit;
    }
};

int main() {
    Solution solver;

    assert(solver.maxProfit({7, 1, 5, 3, 6, 4}) == 5);
    assert(solver.maxProfit({7, 6, 4, 3, 1}) == 0);

    std::cout << "[OK] 0121 - Best Time to Buy and Sell Stock: todos os testes passaram.\n";
    return 0;
}
