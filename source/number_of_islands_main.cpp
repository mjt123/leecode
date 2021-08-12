#include "common/headers.h"

/**
 * @brief The Solution class
 *

给你一个由 '1'（陆地）和 '0'（水）组成的的二维网格，请你计算网格中岛屿的数量。

岛屿总是被水包围，并且每座岛屿只能由水平方向和 / 或竖直方向上相邻的陆地连接形成。

此外，你可以假设该网格的四条边均被水包围。
 */
class Solution {
 private:
  vector<int> dx{0, 0, 1, -1};
  vector<int> dy{1, -1, 0, 0};
  int max_x;
  int max_y;
  void dfs(vector<vector<char>>& grid, vector<vector<bool>> &search_map, int x, int y) {
    if (x < 0 || x > max_x || y < 0 || y > max_y || !search_map[x][y] || grid[x][y] == '0')
      return;
    search_map[x][y] = false;
    for (int i = 0; i < 4; ++i) {
      int new_x = x + dx[i];
      int new_y = y + dy[i];
      dfs(grid, search_map, new_x, new_y);
    }
  }
 public:
  int numIslands(vector<vector<char>>& grid) {

    max_x = grid.size() - 1;
    if (max_x > 0) {
      max_y = grid[0].size() - 1;
    } else {
      return 0;
    }
    int res = 0;
    vector<vector<bool>> search_map(max_x + 1, vector<bool>(max_y + 1, true));

    for (int i = 0; i <= max_x; ++i) {
      for (int j = 0; j <= max_y; ++j) {
        if (search_map[i][j] && grid[i][j] == '1') {
          dfs(grid, search_map, i, j);
          res++;
        }
      }
    }
    return res;
  }
};
