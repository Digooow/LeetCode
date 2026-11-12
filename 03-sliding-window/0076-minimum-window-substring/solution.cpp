#include <array>
#include <cassert>
#include <climits>
#include <iostream>
#include <string>

class Solution {
public:
    std::string minWindow(const std::string& s, const std::string& t) {
        if (t.empty() || s.size() < t.size()) {
            return "";
        }

        std::array<int, 128> need{};
        for (unsigned char c : t) {
            ++need[c];
        }

        int missing = static_cast<int>(t.size());
        int left = 0;
        int bestStart = 0;
        int bestLen = INT_MAX;

        for (int right = 0; right < static_cast<int>(s.size()); ++right) {
            unsigned char rChar = static_cast<unsigned char>(s[right]);
            if (need[rChar] > 0) {
                --missing;
            }
            --need[rChar];

            while (missing == 0) {
                if (right - left + 1 < bestLen) {
                    bestLen = right - left + 1;
                    bestStart = left;
                }

                unsigned char lChar = static_cast<unsigned char>(s[left]);
                ++need[lChar];
                if (need[lChar] > 0) {
                    ++missing;
                }
                ++left;
            }
        }

        return bestLen == INT_MAX ? "" : s.substr(bestStart, bestLen);
    }
};

int main() {
    Solution solver;

    assert(solver.minWindow("ADOBECODEBANC", "ABC") == "BANC");
    assert(solver.minWindow("a", "a") == "a");
    assert(solver.minWindow("a", "aa") == "");

    std::cout << "[OK] 0076 - Minimum Window Substring: todos os testes passaram.\n";
    return 0;
}
