#include <iostream>
#include "common/data_struct/common_struct.h"
#include "common/utilty/debug_message.h"
using namespace std;
/**
 * @brief main
 * @return
 * 给定一个按照升序排列的整数数组 nums，和一个目标值 target。找出给定目标值在数组中的开始位置和结束位置。

如果数组中不存在目标值 target，返回 [-1, -1]。

进阶：

你可以设计并实现时间复杂度为 O(log n) 的算法解决此问题吗？


示例 1：

输入：nums = [5,7,7,8,8,10], target = 8
输出：[3,4]
示例 2：

输入：nums = [5,7,7,8,8,10], target = 6
输出：[-1,-1]
示例 3：

输入：nums = [], target = 0
输出：[-1,-1]
 */
//class Solution {
// private:
//  vector<int> res;
// public:
//  vector<int> searchRange(vector<int>& nums, int target) {

//    if (nums.empty())
//      return { -1, -1};
//    binarySearch(nums, 0, nums.size() - 1, target);
//    if (res.empty())
//      return { -1, -1};
//    if (res.size() == 1) {
//      res.push_back(res[0]);
//    }
//    return {res.front(), res.back()};
//  }
//  void binarySearch(vector<int>& nums, int s, int e, int target) {
//    if (s > e)
//      return;
//    int m = (e - s) / 2 + s;
//    if (s == e) {
//      if (nums[s] == target) {
//        res.push_back(s);
//      }
//      return;
//    }
//    if (nums[m] == target) {
//      binarySearch(nums, s , m - 1, target);
//      res.push_back(m);
//      binarySearch(nums, m + 1, e, target);
//      return;
//    }
//    if (nums[m] < target)
//      binarySearch(nums, m + 1, e, target);
//    if (nums[m] > target)
//      binarySearch(nums, s , m - 1, target);
//    return;
//  }
//};
class Solution {
 public:
  int binarySearch(vector<int>& nums, int target, bool lower) {
    int left = 0, right = (int)nums.size() - 1, ans = (int)nums.size();
    while (left <= right) {
      int mid = (left + right) / 2;
      if (nums[mid] > target || (lower && nums[mid] >= target)) {
        right = mid - 1;
        ans = mid;
      } else {
        left = mid + 1;
      }
    }
    return ans;
  }

  vector<int> searchRange(vector<int>& nums, int target) {
    int leftIdx = binarySearch(nums, target, true);
    int rightIdx = binarySearch(nums, target, false) - 1;
    if (leftIdx <= rightIdx && rightIdx < nums.size() && nums[leftIdx] == target && nums[rightIdx] == target) {
      return vector<int> {leftIdx, rightIdx};
    }
    return vector<int> { -1, -1};
  }
};
int main() {
  vector<int> nums{5, 7, 7, 8, 8, 10};
  Solution solution;
  auto res = solution.searchRange(nums, 8);
  printVector(res);
}
