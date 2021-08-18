#include "common/headers.h"

class Solution {
 private:
  vector<vector<int>> res_;
  vector<bool> vis_;
  void dfs(vector<int>& nums, vector<int>& temp, int cur) {
    if (cur == nums.size() ) {
      res_.emplace_back(temp);
      return ;
    }
    for (int i = 0; i < nums.size(); ++i) {
      if (vis_[i] || (i > 0 && nums[i] == nums[i - 1] && !vis_[i - 1]))
        continue;
      temp.emplace_back(nums[i]);
      vis_[i] = 1;
      dfs(nums, temp, cur + 1);
      vis_[i] = 0;
      temp.pop_back();
    }
  }
 public:
  vector<vector<int>> permuteUnique(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    vector<int> temp;
    vis_ = vector<bool>(nums.size(), false);
//    vis_[0] = true;
    dfs(nums, temp, 0);
    return res_;
  }
};

int main() {
  vector<int> nums{1, 1, 2};
  Solution solution;
  auto res =   solution.permuteUnique(nums);
  printMatrix(res);
  return  0;
}
