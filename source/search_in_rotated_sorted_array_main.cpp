#include "common/data_struct/common_struct.h"
#include <iostream>
#include <math.h>
#include <algorithm>
/**
 * @brief The Solution class
 * 33. 搜索旋转排序数组
整数数组 nums 按升序排列，数组中的值 互不相同 。

在传递给函数之前，nums 在预先未知的某个下标 k（0 <= k < nums.length）上进行了 旋转，使数组变为 [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]]（下标 从 0 开始 计数）。例如， [0,1,2,4,5,6,7] 在下标 3 处经旋转后可能变为 [4,5,6,7,0,1,2] 。

给你 旋转后 的数组 nums 和一个整数 target ，如果 nums 中存在这个目标值 target ，则返回它的下标，否则返回 -1 。



示例 1：

输入：nums = [4,5,6,7,0,1,2], target = 0
输出：4
示例 2：

输入：nums = [4,5,6,7,0,1,2], target = 3
输出：-1
示例 3：

输入：nums = [1], target = 0
输出：-1

 */
class Solution {
 private:
  int res_ = -1;
  void binarySearch(vector<int>& nums, int target, int s, int e) {
//        cout<<s<<" "<<e<<endl;
    if (s > e)
      return;
    int m = (s + e) / 2;
    if (nums[m] == target) {
      res_ = m;
      return;
    }
//        cout<<m<<endl;
    if (nums[s] > nums[e]) {
      if (target < nums[s] && target > nums[e]) {
        return;
      }
      if (nums[m] > nums[std::min(m + 1, (int)nums.size() - 1)]) {

//                cout<<__func__<<" "<<__LINE__<<endl;
        if (nums[e] < target)
          binarySearch(nums, target, s, m - 1);
        else if (nums[s] > target) {
          binarySearch(nums, target, m + 1, e);
        }
      } else {
//                cout<<__func__<<" "<<__LINE__<<endl;
        binarySearch(nums, target, s, m - 1);
        binarySearch(nums, target, m + 1, e);
      }
    } else {
      if (nums[m] > target)
        binarySearch(nums, target, s, m - 1);
      else if (nums[m] < target)
        binarySearch(nums, target, m + 1, e);
    }
  }
 public:
  int search(vector<int>& nums, int target) {
    binarySearch(nums, target, 0, nums.size() - 1);
    return res_;
  }
};
int main() {
  vector<int> nums{4, 5, 6, 7, 8, 1, 2, 3};
//     vector<int> nums{1};
  Solution solution;
  std::cout << solution.search(nums, 8) << endl;;

  return 0;
}
