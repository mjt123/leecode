#include "common/headers.h"

class Solution {
 private:
  vector<unordered_map<int, bool>> hang_;
  vector<unordered_map<int, bool>> lie_;
  vector<unordered_map<int, bool>> block_;
  int blockID(int x, int y) {
    int res = (x / 2) * 2 + (y) / 3;
    return res;
  }
  bool check(int a, int x, int y) {
    bool res = hang_[x][a] && lie_[y][a] && block_[blockID(x, y)][a];
    if (res) {
      hang_[x][a] = false;
    }
  }
  bool res(vector<vector<int>>& matrix,)
 public:
  Solution(): hang_(6), lie_(6), block_(6) {};
  vector<vector<int>> solve(vector<vector<int>> matrix, vector<int> vec) {
    for (int j = 0; j < 6; ++j) {
      for (auto i : vec) {
        hang_[j][i] = true;
        lie_[j][i] = true;
        block_[j][i] = true;
      }
    }
    for (int i = 0; i < 6; i++) {
      for (int j = 0; j < 6; j++) {
        if (matrix[i][j]) {
          hang_[i][matrix[i][j]] = false;
          lie_[j][matrix[i][j]] = false;
          block_[blockID(i, j)][matrix[i][j]] = false;
        }
      }
    }
    vector<vector<int>> res = matrix;
    while (true) {
      for (int i = 0; i < 6; ++i) {
        for (int j = 0; j < 6; ++j) {
          if (matrix[i][j])
            continue;
          for (auto k : vec) {
            if (check(k, i, j)) {

            }
          }
        }
      }
    }
//    matrix
    cout << blockID(4, 2) << endl;
    return {};
  }
};

int main() {
  vector<int> vec{1, 2, 3, 4, 5, 6};
//  vector<vector<int>> matrix(6,vector<int>(6));
  vector<vector<int>> matrix{
    {0, 0, 2, 0, 3, 0},
    {0, 0, 0, 1, 0, 4},
    {2, 0, 0, 0, 4, 0},
    {0, 4, 0, 0, 0, 1},
    {1, 0, 5, 0, 0, 0},
    {0, 6, 0, 5, 0, 0},
  };
  Solution solution;
  solution.solve(matrix, vec);
}
