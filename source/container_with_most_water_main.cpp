#include "common/headers.h"
/**
 * @brief The Solution class
 * 给你 n 个非负整数 a1，a2，...，an，每个数代表坐标中的一个点 (i, ai) 。在坐标内画 n 条垂直线，垂直线 i 的两个端点分别为 (i, ai) 和 (i, 0) 。找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。

说明：你不能倾斜容器。
输入：[1,8,6,2,5,4,8,3,7]
输出：49
解释：图中垂直线代表输入数组 [1,8,6,2,5,4,8,3,7]。在此情况下，容器能够容纳水（表示为蓝色部分）的最大值为 49。
 */
class Solution {
 public:
  int area(vector<int>& height, int a, int b) {
    int h = min(height[a], height[b]);
    return h * (b - a);
  }
  int maxArea(vector<int>& height) {
    if (height.size() < 2)
      return 0;
    int a = 0;
    int b = height.size() - 1;
    int max_area = 0;
    while (a < b) {
      int s = area(height, a, b);
      max_area = max(s, max_area);
      height[a] < height[b] ? a++ : b--;
    }
    return max_area;
  }
};
int main() {
  vector<int> nums{1, 8, 6, 2, 5, 4, 8, 3, 7};
  Solution solution;
  cout << solution.maxArea(nums) << endl;;
}
