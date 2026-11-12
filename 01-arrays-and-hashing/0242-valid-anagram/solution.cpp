#include <array>
#include <cassert>
#include <iostream>
#include <string>

class Solution {
public:
    bool isAnagram(const std::string& s, const std::string& t) {
        if (s.size() != t.size()) {
            return false;
        }

        std::array<int, 26> freq{};
        for (std::size_t i = 0; i < s.size(); ++i) {
            ++freq[s[i] - 'a'];
            --freq[t[i] - 'a'];
        }

        for (int count : freq) {
            if (count != 0) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    Solution solver;

    assert(solver.isAnagram("anagram", "nagaram") == true);
    assert(solver.isAnagram("rat", "car") == false);
    assert(solver.isAnagram("ab", "a") == false);

    std::cout << "[OK] 0242 - Valid Anagram: todos os testes passaram.\n";
    return 0;
}
