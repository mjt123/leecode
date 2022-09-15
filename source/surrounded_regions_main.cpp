#include "common/headers.h"

/**
 * @brief The Solution class
 * 给你一个 m x n 的矩阵 board ，由若干字符 'X' 和 'O' ，找到所有被 'X' 围绕的区域，并将这些区域里所有的 'O' 用 'X' 填充。
 * 输入：board = [["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]
输出：[["X","X","X","X"],["X","X","X","X"],["X","X","X","X"],["X","O","X","X"]]
 */
class Solution {
 private:
  int m;
  int n;
  vector<int> dx{1, -1, 0, 0};
  vector<int> dy{0, 0, 1, -1};
  bool outBoard(int x, int y) {
    if (x > m - 1 || x < 0 || y < 0 || y > n - 1)
      return true;
    return false;
  }
 public:
  void solve(vector<vector<char>>& board) {
    m = board.size();
    if (m == 0)
      return;
    n = board[0].size();
    queue<pair<int, int>> q;
    vector<vector<bool>> searched(m, vector<bool>(n, false));
    for (int i = 1; i < m - 1; ++i) {
      for (int j = 1; j < n - 1; ++j) {
        if (board[i][j] == 'O' && !searched[i][j]) {
          q.push({i, j});
          vector<pair<int, int>> vec;
          vec.push_back({i, j});
          bool change = true;
          searched[i][j] = true;
          while (!q.empty()) {
            int size = q.size();
            for (int s = 0; s < size; s++) {
              auto temp = q.front();
              q.pop();
              for (int k = 0; k < 4; ++k) {
                int new_x = temp.first + dx[k];
                int new_y = temp.second + dy[k];
                if (!outBoard(new_x, new_y) && !searched[new_x][new_y]) {
                  if (board[new_x][new_y] == 'O') {
                    if (new_x == 0 || new_x == m - 1 || new_y == 0 || new_y == n - 1) {
                      change = false;
                    }
                    q.push({new_x, new_y});
                    searched[new_x][new_y] = true;
                    if (change)
                      vec.push_back({new_x, new_y});
                  }
                }
              }
            }
          }
          if (change) {
            for (auto i : vec) {
              board[i.first][i.second] = 'X';
            }
          }
        }
      }
    }
  }
};
int main() {
  vector<vector<char>> board{{'X', 'X', 'X', 'X'}, {'X', 'O', 'O', 'X'}, {'X', 'X', 'O', 'X'}, {'X', 'O', 'X', 'X'}};
  Solution  solution;
  solution.solve(board);
  printMatrix(board);
}
