#include "common/headers.h"
/**
 * @brief The Solution class
 * 给定两个由一些 闭区间 组成的列表，firstList 和 secondList ，其中 firstList[i] = [starti, endi] 而 secondList[j] = [startj, endj] 。每个区间列表都是成对 不相交 的，并且 已经排序 。

返回这 两个区间列表的交集 。

形式上，闭区间 [a, b]（其中 a <= b）表示实数 x 的集合，而 a <= x <= b 。

两个闭区间的 交集 是一组实数，要么为空集，要么为闭区间。例如，[1, 3] 和 [2, 4] 的交集为 [2, 3] 。

输入：firstList = [[0,2],[5,10],[13,23],[24,25]], secondList = [[1,5],[8,12],[15,24],[25,26]]
输出：[[1,2],[5,5],[8,10],[15,23],[24,24],[25,25]]

 */
class Solution {
 public:
  vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
    int i = 0;
    int j = 0;
    vector<vector<int>> res;
    while (i < firstList.size() && j < secondList.size()) {
      if (firstList[i][0] <= secondList[j][0] && firstList[i][1] >= secondList[j][0]) {
        if (firstList[i][1] >= secondList[j][1]) {
          vector<int> temp{secondList[j][0], secondList[j][1]};
          res.push_back(temp);
          j++;
        } else {
          vector<int> temp{secondList[j][0], firstList[i][1]};
          res.push_back(temp);
          i++;
        }
      } else if (secondList[j][0] <= firstList[i][0] && secondList[j][1] >= firstList[i][0]) {
        if (firstList[i][1] >= secondList[j][1]) {
          vector<int> temp{firstList[i][0], secondList[j][1]};
          res.push_back(temp);
          j++;
        } else {
          vector<int> temp{firstList[i][0], firstList[i][1]};
          res.push_back(temp);
          i++;
        }
      } else if (firstList[i][1] < secondList[j][0]) {
        COUTFUNC;

        i++;
      } else {
        COUTFUNC;

        j++;
      }
    }
    return res;
  }
};
int main() {
//  vector<vector<int>> firstlist{{0, 2}, {5, 10}, {13, 23}, {24, 25}};
//  vector<vector<int>> secondlist{{1, 5}, {8, 12}, {15, 24}, {25, 26}};

  vector<vector<int>> firstlist{{5, 10}};
  vector<vector<int>> secondlist{{5, 6}};
  Solution solution;
  auto res = solution.intervalIntersection(firstlist, secondlist);
  printMatrix(res);
  return 0;
}
