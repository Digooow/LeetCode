#include <cassert>
#include <iostream>
#include <stack>
#include <string>

class Solution {
public:
    bool isValid(const std::string& s) {
        std::stack<char> expected;

        for (char c : s) {
            if (c == '(') {
                expected.push(')');
            } else if (c == '[') {
                expected.push(']');
            } else if (c == '{') {
                expected.push('}');
            } else {
                if (expected.empty() || expected.top() != c) {
                    return false;
                }
                expected.pop();
            }
        }

        return expected.empty();
    }
};

int main() {
    Solution solver;

    assert(solver.isValid("()") == true);
    assert(solver.isValid("()[]{}") == true);
    assert(solver.isValid("(]") == false);
    assert(solver.isValid("([])") == true);

    std::cout << "[OK] 0020 - Valid Parentheses: todos os testes passaram.\n";
    return 0;
}
