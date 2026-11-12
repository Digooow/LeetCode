#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

class Solution {
public:
    std::vector<std::vector<std::string>> groupAnagrams(const std::vector<std::string>& strs) {
        std::unordered_map<std::string, std::vector<std::string>> groups;

        for (const std::string& s : strs) {
            std::string canonicalKey = s;
            std::sort(canonicalKey.begin(), canonicalKey.end());
            groups[canonicalKey].push_back(s);
        }

        std::vector<std::vector<std::string>> result;
        result.reserve(groups.size());
        for (auto& [key, bucket] : groups) {
            result.push_back(std::move(bucket));
        }

        return result;
    }
};

int main() {
    Solution solver;

    auto res = solver.groupAnagrams({"eat", "tea", "tan", "ate", "nat", "bat"});
    assert(res.size() == 3);

    auto single = solver.groupAnagrams({""});
    assert(single.size() == 1 && single[0].size() == 1 && single[0][0].empty());

    std::cout << "[OK] 0049 - Group Anagrams: todos os testes passaram.\n";
    return 0;
}
