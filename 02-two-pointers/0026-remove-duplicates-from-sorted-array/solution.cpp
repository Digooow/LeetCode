#include <cassert>
#include <iostream>
#include <vector>

class Solution {
public:
    int removeDuplicates(std::vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }

        int write = 1;
        for (std::size_t read = 1; read < nums.size(); ++read) {
            if (nums[read] != nums[write - 1]) {
                nums[write] = nums[read];
                ++write;
            }
        }

        return write;
    }
};

int main() {
    Solution solver;

    std::vector<int> nums1 = {1, 1, 2};
    int k1 = solver.removeDuplicates(nums1);
    assert(k1 == 2 && nums1[0] == 1 && nums1[1] == 2);

    std::vector<int> nums2 = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    int k2 = solver.removeDuplicates(nums2);
    assert(k2 == 5);

    std::cout << "[OK] 0026 - Remove Duplicates from Sorted Array: todos os testes passaram.\n";
    return 0;
}
