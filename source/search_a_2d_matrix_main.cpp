#include <iostream>
#include "common/data_struct/common_struct.h"

/**
 * @brief main
 * @return
 * 编写一个高效的算法来判断 m x n 矩阵中，是否存在一个目标值。该矩阵具有如下特性：

每行中的整数从左到右按升序排列。
每行的第一个整数大于前一行的最后一个整数。


示例 1：


输入：matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
输出：true
 */
class Solution {
public:

//    bool searchMatrix(vector<vector<int>>& matrix, int target) {
////       int upper=0;
////       int lower=matrix.size()-1;
////        int left=0;
////       int right=matrix[0].size()-1;
////       int mid;
////       while(upper>lower){
////            mid=(upper)
////       }
//        int x=matrix.size();
//        if(x==0)
//            return false;
//        int y=matrix[0].size();

//        int s=0;
//        int e=x*y-1;
//        while(s<=e){
//            int m=(s+e)/2;
//            int i=m/y;
//            int j=m%y;
//            if(matrix[i][j]==target)
//                return true;
//            if(matrix[i][j]<target)
//                s=m+1;
//            else {
//                e=m-1;
//            }
//        }
//        return false;
//    }
     bool searchMatrix2(vector<vector<int>>& matrix, int target) {
        int upper=0;
        int lower=matrix.size()-1;
        int m;
        while(upper<=lower){
            m=(upper+lower)/2;
            if(matrix[m][0]<target){
                upper=m+1;
            }else if(matrix[m][0]>target){
                lower=m-1;
            }else {
                return true;
            }
        }
       upper=max(0,--upper);
       cout<<upper<<endl;
        int left=0;
        int right=matrix[upper].size()-1;
        while(left<=right){
            m=(left+right)/2;
            if(matrix[upper][m]==target)
                return true;
            if(matrix[upper][m]<target)
                left=m+1;
            else {
                right=m-1;
            }
        }
        return false;
     }
};
int main(){
    vector<vector<int>> matrix{{1,3,5,7},{10,11,16,20},{23,30,34,60}};
//    vector<vector<int>> matrix{{1}};
    Solution solution;
    std::cout<<solution.searchMatrix2(matrix, 3)<<std::endl;
    return 0;
}
