#include <cassert>
#include <iostream>
#include <vector>

class Solution {
    void sinkIsland(std::vector<std::vector<char>>& grid, int r, int c) {
        const int rows = static_cast<int>(grid.size());
        const int cols = static_cast<int>(grid[0].size());

        if (r < 0 || r >= rows || c < 0 || c >= cols || grid[r][c] != '1') {
            return;
        }

        grid[r][c] = '0';
        sinkIsland(grid, r + 1, c);
        sinkIsland(grid, r - 1, c);
        sinkIsland(grid, r, c + 1);
        sinkIsland(grid, r, c - 1);
    }

public:
    int numIslands(std::vector<std::vector<char>> grid) {
        if (grid.empty() || grid[0].empty()) {
            return 0;
        }

        int islands = 0;
        const int rows = static_cast<int>(grid.size());
        const int cols = static_cast<int>(grid[0].size());

        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                if (grid[r][c] == '1') {
                    ++islands;
                    sinkIsland(grid, r, c);
                }
            }
        }

        return islands;
    }
};

int main() {
    Solution solver;

    std::vector<std::vector<char>> grid1 = {
        {'1', '1', '1', '1', '0'},
        {'1', '1', '0', '1', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '0', '0', '0'}
    };
    assert(solver.numIslands(grid1) == 1);

    std::vector<std::vector<char>> grid2 = {
        {'1', '1', '0', '0', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '1', '0', '0'},
        {'0', '0', '0', '1', '1'}
    };
    assert(solver.numIslands(grid2) == 3);

    std::cout << "[OK] 0200 - Number of Islands: todos os testes passaram.\n";
    return 0;
}
