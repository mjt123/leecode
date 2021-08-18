#include "common/headers.h"
/**
 * @brief The Solution class
1.给你一个整数数组 nums ，数组中的元素 互不相同 。返回该数组所有可能的子集（幂集）。

解集 不能 包含重复的子集。你可以按 任意顺序 返回解集。
示例 1：

输入：nums = [1,2,3]
输出：[[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
示例 2：

输入：nums = [0]
输出：[[],[0]]

2.给你一个整数数组 nums ，其中可能包含重复元素，请你返回该数组所有可能的子集（幂集）。

解集 不能 包含重复的子集。返回的解集中，子集可以按 任意顺序 排列。
示例 1：

输入：nums = [1,2,2]
输出：[[],[1],[1,2],[1,2,2],[2],[2,2]]
示例 2：

输入：nums = [0]
输出：[[],[0]]
*/
class Solution {
 private:
  vector<vector<int>> res_;
  void dfs(vector<int> &nums, int cur, vector<int>& vec) {
    if (cur == nums.size()) {
      res_.emplace_back(vec);
      return;
    }
    vec.emplace_back(nums[cur]);
    dfs(nums, cur + 1, vec);
    vec.pop_back();
    dfs(nums, cur + 1, vec);
  }
 public:
  vector<vector<int>> subsets(vector<int>& nums) {
    vector<int> vec;
    dfs(nums, 0, vec);
    return res_;
  }
//  vector<vector<int>> subsetsWithDup(vector<int>& nums) {

//  }
};

int main() {
  vector<int> nums{1, 2, 3};
  Solution solution;
  auto res = solution.subsets(nums);
  printMatrix(res);
  return 0;
}
