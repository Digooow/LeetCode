#include <cassert>
#include <iostream>
#include <stack>
#include <vector>

class Solution {
public:
    std::vector<int> dailyTemperatures(const std::vector<int>& temperatures) {
        const int n = static_cast<int>(temperatures.size());
        std::vector<int> answer(n, 0);
        std::stack<int> pendingIndices;

        for (int i = 0; i < n; ++i) {
            while (!pendingIndices.empty() &&
                   temperatures[i] > temperatures[pendingIndices.top()]) {
                int prevDay = pendingIndices.top();
                pendingIndices.pop();
                answer[prevDay] = i - prevDay;
            }
            pendingIndices.push(i);
        }

        return answer;
    }
};

int main() {
    Solution solver;

    assert((solver.dailyTemperatures({73, 74, 75, 71, 69, 72, 76, 73}) ==
            std::vector<int>{1, 1, 4, 2, 1, 1, 0, 0}));
    assert((solver.dailyTemperatures({30, 40, 50, 60}) ==
            std::vector<int>{1, 1, 1, 0}));

    std::cout << "[OK] 0739 - Daily Temperatures: todos os testes passaram.\n";
    return 0;
}
