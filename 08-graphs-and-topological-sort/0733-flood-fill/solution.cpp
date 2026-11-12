#include <cassert>
#include <iostream>
#include <vector>

class Solution {
    void dfs(std::vector<std::vector<int>>& image, int r, int c, int originalColor, int newColor) {
        const int rows = static_cast<int>(image.size());
        const int cols = static_cast<int>(image[0].size());

        if (r < 0 || r >= rows || c < 0 || c >= cols || image[r][c] != originalColor) {
            return;
        }

        image[r][c] = newColor;
        dfs(image, r + 1, c, originalColor, newColor);
        dfs(image, r - 1, c, originalColor, newColor);
        dfs(image, r, c + 1, originalColor, newColor);
        dfs(image, r, c - 1, originalColor, newColor);
    }

public:
    std::vector<std::vector<int>> floodFill(
        std::vector<std::vector<int>> image, int sr, int sc, int color) {
        int originalColor = image[sr][sc];
        if (originalColor != color) {
            dfs(image, sr, sc, originalColor, color);
        }
        return image;
    }
};

int main() {
    Solution solver;

    auto res = solver.floodFill({{1, 1, 1}, {1, 1, 0}, {1, 0, 1}}, 1, 1, 2);
    std::vector<std::vector<int>> expected = {{2, 2, 2}, {2, 2, 0}, {2, 0, 1}};
    assert(res == expected);

    std::cout << "[OK] 0733 - Flood Fill: todos os testes passaram.\n";
    return 0;
}
