#include "common/headers.h"
#include <memory>
#include <string>
#include "string.h"
//class Solution {
// private:
//  vector<unordered_map<int, bool>> hang_;
//  vector<unordered_map<int, bool>> lie_;
//  vector<unordered_map<int, bool>> block_;
//  int blockID(int x, int y) {
//    int res = (x / 2) * 2 + (y) / 3;
//    return res;
//  }
//  bool check(int a, int x, int y) {
//    bool res = hang_[x][a] && lie_[y][a] && block_[blockID(x, y)][a];
//    if (res) {
//      hang_[x][a] = false;
//    }
//  }
//  bool res(vector<vector<int>>& matrix,)
// public:
//  Solution(): hang_(6), lie_(6), block_(6) {};
//  vector<vector<int>> solve(vector<vector<int>> matrix, vector<int> vec) {
//    for (int j = 0; j < 6; ++j) {
//      for (auto i : vec) {
//        hang_[j][i] = true;
//        lie_[j][i] = true;
//        block_[j][i] = true;
//      }
//    }
//    for (int i = 0; i < 6; i++) {
//      for (int j = 0; j < 6; j++) {
//        if (matrix[i][j]) {
//          hang_[i][matrix[i][j]] = false;
//          lie_[j][matrix[i][j]] = false;
//          block_[blockID(i, j)][matrix[i][j]] = false;
//        }
//      }
//    }
//    vector<vector<int>> res = matrix;
//    while (true) {
//      for (int i = 0; i < 6; ++i) {
//        for (int j = 0; j < 6; ++j) {
//          if (matrix[i][j])
//            continue;
//          for (auto k : vec) {
//            if (check(k, i, j)) {

//            }
//          }
//        }
//      }
//    }
////    matrix
//    cout << blockID(4, 2) << endl;
//    return {};
//  }
//};
//class Solution {
// private:
//  bool line[6][6];
//  bool column[6][6];
//  bool block[3][2][6];
//  bool valid;
//  vector<pair<int, int>> spaces;

// public:
//  void dfs(vector<vector<char>>& board, int pos) {
//    if (pos == spaces.size()) {
//      valid = true;
//      return;
//    }

//    auto [i, j] = spaces[pos];
//    for (int digit = 0; digit < 6 && !valid; ++digit) {
//      if (!line[i][digit] && !column[j][digit] && !block[i / 2][j / 3][digit]) {
//        line[i][digit] = column[j][digit] = block[i / 2][j / 3][digit] = true;
//        board[i][j] = digit + '0' + 1;
//        dfs(board, pos + 1);
//        line[i][digit] = column[j][digit] = block[i / 2][j / 3][digit] = false;
//      }
//    }
//  }

//  void solveSudoku(vector<vector<char>>& board) {
//    memset(line, false, sizeof(line));
//    memset(column, false, sizeof(column));
//    memset(block, false, sizeof(block));
//    valid = false;

//    for (int i = 0; i < 6; ++i) {
//      for (int j = 0; j < 6; ++j) {
//        if (board[i][j] == '.') {
//          spaces.emplace_back(i, j);
//        } else {
//          int digit = board[i][j] - '0' - 1;
//          line[i][digit] = column[j][digit] = block[i / 2][j / 3][digit] = true;
//        }
//      }
//    }

//    dfs(board, 0);
//  }
//};
class Solution {
 private:
  bool line[9][9];
  bool column[9][9];
  bool block[3][3][9];
  bool valid;
  vector<pair<int, int>> spaces;

 public:
  void dfs(vector<vector<char>>& board, int pos) {
    if (pos == spaces.size()) {
      valid = true;
      return;
    }

    auto [i, j] = spaces[pos];
    for (int digit = 0; digit < 9 && !valid; ++digit) {
      if (!line[i][digit] && !column[j][digit] && !block[i / 3][j / 3][digit]) {
        line[i][digit] = column[j][digit] = block[i / 3][j / 3][digit] = true;
        board[i][j] = digit + '0' + 1;
        dfs(board, pos + 1);
        line[i][digit] = column[j][digit] = block[i / 3][j / 3][digit] = false;
      }
    }
  }

  void solveSudoku(vector<vector<char>>& board) {
    memset(line, false, sizeof(line));
    memset(column, false, sizeof(column));
    memset(block, false, sizeof(block));
    valid = false;

    for (int i = 0; i < 9; ++i) {
      for (int j = 0; j < 9; ++j) {
        if (board[i][j] == '.') {
          spaces.emplace_back(i, j);
        } else {
          int digit = board[i][j] - '0' - 1;
          line[i][digit] = column[j][digit] = block[i / 3][j / 3][digit] = true;
        }
      }
    }

    dfs(board, 0);
  }
};
int main() {
  vector<int> vec{1, 2, 3, 4, 5, 6};
//  vector<vector<int>> matrix(6,vector<int>(6));
//  vector<vector<char>> matrix{
//    {'.', '.', '4', '.', '1', '.'},
//    {'3', '.', '.', '6', '.', '.'},
//    {'.', '1', '.', '.', '.', '6'},
//    {'2', '.', '.', '.', '5', '.'},
//    {'.', '.', '6', '.', '.', '2'},
//    {'.', '3', '.', '1', '.', '.'},
//  };
  vector<vector<char>> matrix1{
    {'.', '.', '.', '.', '.', '.', '.', '.', '.'},
    {'.', '.', '.', '.', '.', '.', '.', '.', '.'},
    {'.', '.', '.', '.', '.', '.', '.', '.', '.'},
    {'.', '.', '.', '.', '.', '.', '.', '.', '.'},
    {'.', '.', '.', '.', '.', '.', '.', '.', '.'},
    {'.', '.', '.', '.', '.', '.', '.', '.', '.'},
    {'.', '.', '.', '.', '.', '.', '.', '.', '.'},
    {'.', '.', '.', '.', '.', '.', '.', '.', '.'},
    {'.', '.', '.', '.', '.', '.', '.', '.', '.'}
  };
  vector<vector<char>> matrix2{
    {'5', '.', '.', '.', '.', '3', '.', '.', '.'},
    {'.', '.', '.', '.', '.', '.', '3', '2', '9'},
    {'3', '.', '4', '.', '7', '9', '.', '.', '.'},
    {'.', '5', '.', '.', '2', '.', '8', '3', '.'},
    {'.', '.', '.', '1', '.', '6', '.', '.', '.'},
    {'.', '2', '7', '.', '8', '.', '.', '1', '.'},
    {'.', '.', '.', '4', '3', '.', '1', '.', '2'},
    {'8', '4', '1', '.', '.', '.', '.', '.', '.'},
    {'.', '.', '.', '5', '.', '.', '.', '.', '8'}
  };
  vector<vector<char>> matrix3{
    {'.', '7', '.', '6', '.', '3', '.', '4', '.'},
    {'.', '2', '.', '.', '.', '.', '.', '3', '.'},
    {'6', '.', '.', '.', '4', '.', '.', '.', '5'},
    {'.', '.', '4', '9', '.', '5', '3', '.', '.'},
    {'.', '.', '3', '.', '.', '.', '5', '.', '.'},
    {'.', '.', '8', '4', '.', '6', '7', '.', '.'},
    {'3', '.', '.', '.', '9', '.', '.', '.', '1'},
    {'.', '8', '.', '.', '.', '.', '.', '5', '.'},
    {'.', '5', '.', '3', '.', '2', '.', '7', '.'}
  };
  Solution solution;
  solution.solveSudoku(matrix3);
  printMatrix(matrix3);
}
