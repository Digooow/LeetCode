#include <algorithm>
#include <cassert>
#include <iostream>
#include <unordered_set>
#include <vector>

class Solution {
public:
    int longestConsecutive(const std::vector<int>& nums) {
        std::unordered_set<int> numSet(nums.begin(), nums.end());
        int longest = 0;

        for (int num : numSet) {
            if (numSet.find(num - 1) == numSet.end()) {
                int currentNum = num;
                int currentStreak = 1;

                while (numSet.find(currentNum + 1) != numSet.end()) {
                    ++currentNum;
                    ++currentStreak;
                }

                longest = std::max(longest, currentStreak);
            }
        }

        return longest;
    }
};

int main() {
    Solution solver;

    assert(solver.longestConsecutive({100, 4, 200, 1, 3, 2}) == 4);
    assert(solver.longestConsecutive({0, 3, 7, 2, 5, 8, 4, 6, 0, 1}) == 9);

    std::cout << "[OK] 0128 - Longest Consecutive Sequence: todos os testes passaram.\n";
    return 0;
}
