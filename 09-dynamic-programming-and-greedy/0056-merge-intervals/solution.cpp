#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> merge(std::vector<std::vector<int>> intervals) {
        if (intervals.empty()) {
            return {};
        }

        std::sort(intervals.begin(), intervals.end());
        std::vector<std::vector<int>> merged;
        merged.push_back(intervals[0]);

        for (std::size_t i = 1; i < intervals.size(); ++i) {
            if (intervals[i][0] <= merged.back()[1]) {
                merged.back()[1] = std::max(merged.back()[1], intervals[i][1]);
            } else {
                merged.push_back(intervals[i]);
            }
        }

        return merged;
    }
};

int main() {
    Solution solver;

    auto res1 = solver.merge({{1, 3}, {2, 6}, {8, 10}, {15, 18}});
    std::vector<std::vector<int>> exp1 = {{1, 6}, {8, 10}, {15, 18}};
    assert(res1 == exp1);

    auto res2 = solver.merge({{1, 4}, {4, 5}});
    std::vector<std::vector<int>> exp2 = {{1, 5}};
    assert(res2 == exp2);

    std::cout << "[OK] 0056 - Merge Intervals: todos os testes passaram.\n";
    return 0;
}
