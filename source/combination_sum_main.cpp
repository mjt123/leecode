#include "common/headers.h"
/**
 * @brief The Solution class
 * 给定一个无重复元素的正整数数组 candidates 和一个正整数 target ，找出 candidates 中所有可以使数字和为目标数 target 的唯一组合。

candidates 中的数字可以无限制重复被选取。如果至少一个所选数字数量不同，则两种组合是唯一的。

对于给定的输入，保证和为 target 的唯一组合数少于 150 个。
示例 1：

输入: candidates = [2,3,6,7], target = 7
输出: [[7],[2,2,3]]
示例 2：

输入: candidates = [2,3,5], target = 8
输出: [[2,2,2,2],[2,3,3],[3,5]]
 */
class Solution {
 private:
  vector<vector<int>> res;
  void dfs(vector<int>& candidates, vector<int>& temp, int cur, int target) {
    if (cur == candidates.size() || target <= 0) {
      if (target == 0)
        res.emplace_back(temp);
      return;
    }
//    target=target-candidates[cur];
    dfs(candidates, temp, cur + 1, target);
    temp.emplace_back(candidates[cur]);
    dfs(candidates, temp, cur, target - candidates[cur]);
    temp.pop_back();
  }
 public:
  vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<int> temp;
    dfs(candidates, temp, 0, target);
    return res;
  }
  /**
   * @brief combinationSum2
   * 给定一个数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。
  candidates 中的每个数字在每个组合中只能使用一次。
  注意：解集不能包含重复的组合。
  示例 1:

  输入: candidates = [10,1,2,7,6,1,5], target = 8,
  输出:
  [
  [1,1,6],
  [1,2,5],
  [1,7],
  [2,6]
  ]
  示例 2:

  输入: candidates = [2,5,2,1,2], target = 5,
  输出:
  [
  [1,2,2],
  [5]
  ]
   * @param candidates
   * @param target
   * @return
   */
  void dfs(vector<int>& candidates, vector<int>& temp, vector<bool>& vis, int cur, int target) {
    if (cur == candidates.size() || target <= 0) {
      if (target == 0)
        res.emplace_back(temp);
      return;
    }

    dfs(candidates, temp, vis, cur + 1, target);
    if (!(cur > 0 && candidates[cur] == candidates[cur - 1] && !vis[cur - 1])) {
      vis[cur] = true;
      temp.emplace_back(candidates[cur]);
      dfs(candidates, temp, vis, cur + 1, target - candidates[cur]);
      temp.pop_back();
      vis[cur] = false;
    }
  }
  vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    sort(candidates.begin(), candidates.end());
    vector<bool> vis(candidates.size(), false);
    vector<int> temp;
    dfs(candidates, temp, vis, 0, target);
    return res;
  }
};
int main() {
  vector<int> nums{10, 1, 2, 7, 6, 1, 5};
  Solution solution;
  auto res =   solution.combinationSum2(nums, 8);
  printMatrix(res);
  return 0;
}
