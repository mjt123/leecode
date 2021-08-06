
#include <iostream>

#include "common/data_struct/common_struct.h"
using namespace std;
/**
 * @brief The Solution class
 * 输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历结果。如果是则返回 true，否则返回 false。假设输入的数组的任意两个数字都互不相同。

参考以下这颗二叉搜索树：
     5
    / \
   2   6
  / \
 1   3
示例 1：

输入: [1,6,3,2,5]
输出: false
示例 2：

输入: [1,3,2,6,5]
输出: true
 */
class Solution {
 public:
  vector<int> res;
  bool verifyPostorder(vector<int>& postorder) {
    res = postorder;
    return dfs(0, postorder.size() - 1);
  }
  bool dfs(int l, int r) {
    if (l >= r) return true; //退出条件
    int root = res[r];//最后一个点是根结点
    int k = l;//从最左边开始
    while (k < r && res[k] < root) k++; //符合左子树的点
    for (int i = k; i < r; i++) { //此时的k是右子树的第一个点
      if (res[i] < root) //如果右子树小于根，说明不符合
        return false;
    }
    return dfs(l, k - 1) && dfs(k, r - 1);//逐步缩小范围
  }
};
int main() {
  vector<int> nums1{1, 3, 2, 6, 5};
  vector<int> nums2{1, 6, 3, 2, 5};
  Solution solve;
  cout <<  solve.verifyPostorder(nums1) << endl;
  cout <<  solve.verifyPostorder(nums2) << endl;
}
