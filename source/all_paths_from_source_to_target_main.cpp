#include <functional>
#include "common/headers.h"
/**
 * @brief The Solution class
 * 给一个有 n 个结点的有向无环图，找到所有从 0 到 n-1 的路径并输出（不要求按顺序）

二维数组的第 i 个数组中的单元都表示有向图中 i 号结点所能到达的下一些结点（译者注：有向图是有方向的，即规定了 a→b 你就不能从 b→a ）空就是没有下一个结点了。
输入：graph = [[1,2],[3],[3],[]]
输出：[[0,1,3],[0,2,3]]
解释：有两条路径 0 -> 1 -> 3 和 0 -> 2 -> 3
 */
class Solution {
 private:
  vector<vector<int>> paths_;
  unordered_map < int, vector<vector<int>>> map_;
 public:
  void dfs(vector<vector<int>>& graph, int id, vector<int>& path) {
    if (id == graph.size() - 1) {
      paths_.push_back(path);
      return;
    }
    if (graph[id].empty()) {
      return;
    }
    for (auto i : graph[id]) {
      path.push_back(i);
      dfs(graph, i, path);
      path.pop_back();
    }
    return;
  }
  vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
    if (graph.empty())
      return {};
    vector<int> path{0};
    dfs(graph, 0, path);
    return paths_;
  }
};
//class Solution {
// public:
//  vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
//    vector<vector<int>> res;
//    int n = graph.size();
//    function<void(int , vector<int>&)> dfs = [&](int cur, vector<int>& temp) {
//      if (cur == n - 1) { //当遍历到最终节点将当前路径加入答案
//        res.emplace_back(temp);
//        return;
//      }
//      auto&& vec = graph[cur];
//      for (auto && i : vec) { //遍历当前节点所能到达的所有边
//        temp.emplace_back(i);   //将当前能到达的顶点加入路径
//        dfs(i, temp);   //递归下一层
//        temp.pop_back();    //回溯
//      }
//    };
//    vector<int> temp{0};    //初始化路径为起始顶点0
//    dfs(0, temp);
//    return res;
//  }
//};
int main() {
  vector<vector<int>> graph{{1, 2}, {3}, {3}, {}};
  Solution solution;
  auto res = solution.allPathsSourceTarget(graph);
  printMatrix(res);
  return 0;
}
