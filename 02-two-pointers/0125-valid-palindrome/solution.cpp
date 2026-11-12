#include <cassert>
#include <cctype>
#include <iostream>
#include <string>

class Solution {
public:
    bool isPalindrome(const std::string& s) {
        int left = 0;
        int right = static_cast<int>(s.size()) - 1;

        while (left < right) {
            while (left < right && !std::isalnum(static_cast<unsigned char>(s[left]))) {
                ++left;
            }
            while (left < right && !std::isalnum(static_cast<unsigned char>(s[right]))) {
                --right;
            }

            if (std::tolower(static_cast<unsigned char>(s[left])) !=
                std::tolower(static_cast<unsigned char>(s[right]))) {
                return false;
            }

            ++left;
            --right;
        }

        return true;
    }
};

int main() {
    Solution solver;

    assert(solver.isPalindrome("A man, a plan, a canal: Panama") == true);
    assert(solver.isPalindrome("race a car") == false);
    assert(solver.isPalindrome(" ") == true);

    std::cout << "[OK] 0125 - Valid Palindrome: todos os testes passaram.\n";
    return 0;
}
