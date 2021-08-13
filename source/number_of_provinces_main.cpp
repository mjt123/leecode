#include "common/headers.h"

/**
 * @brief The Solution class
 * 有 n 个城市，其中一些彼此相连，另一些没有相连。如果城市 a 与城市 b 直接相连，且城市 b 与城市 c 直接相连，那么城市 a 与城市 c 间接相连。

省份 是一组直接或间接相连的城市，组内不含其他没有相连的城市。

给你一个 n x n 的矩阵 isConnected ，其中 isConnected[i][j] = 1 表示第 i 个城市和第 j 个城市直接相连，而 isConnected[i][j] = 0 表示二者不直接相连。

返回矩阵中 省份 的数量。

 */
class Solution {
 private:
  int city_size_;
//  int max_y_;
 private:
  void dfs(vector<vector<int>>& isConnected, int a) {
//    bool is_a_provience = false;
    isConnected[a][a] = false;

    for (int i = 0; i < city_size_; ++i) {
      if (isConnected[a][i]) {
        isConnected[a][i] = 0;
        isConnected[i][a] = 0;
        dfs(isConnected, i);
      }
    }
  }
 public:
  int findCircleNum(vector<vector<int>>& isConnected) {
    city_size_ =  isConnected.size();
    if (city_size_ == 0)
      return 0;
    int res = 0;
    for (int i = 0; i < city_size_; ++i) {
      if (isConnected[i][i]) {
        res++;
        dfs(isConnected, i);
      }
    }
    return res;
  }
};
int main() {
  vector<vector<int>> isConnected{{1, 0, 0, 1}, {0, 1, 1, 0}, {0, 1, 1, 1}, {1, 0, 1, 1}};
  Solution solution;
  cout << solution.findCircleNum(isConnected) << endl;
  printMatrix(isConnected);
  return 0;
}
