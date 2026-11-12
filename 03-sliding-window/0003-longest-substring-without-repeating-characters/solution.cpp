#include <algorithm>
#include <array>
#include <cassert>
#include <iostream>
#include <string>

class Solution {
public:
    int lengthOfLongestSubstring(const std::string& s) {
        std::array<int, 256> lastSeen;
        lastSeen.fill(-1);

        int left = 0;
        int maxLen = 0;

        for (int right = 0; right < static_cast<int>(s.size()); ++right) {
            unsigned char c = static_cast<unsigned char>(s[right]);
            if (lastSeen[c] >= left) {
                left = lastSeen[c] + 1;
            }
            lastSeen[c] = right;
            maxLen = std::max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};

int main() {
    Solution solver;

    assert(solver.lengthOfLongestSubstring("abcabcbb") == 3);
    assert(solver.lengthOfLongestSubstring("bbbbb") == 1);
    assert(solver.lengthOfLongestSubstring("pwwkew") == 3);
    assert(solver.lengthOfLongestSubstring("") == 0);

    std::cout << "[OK] 0003 - Longest Substring Without Repeating Characters: todos os testes passaram.\n";
    return 0;
}
