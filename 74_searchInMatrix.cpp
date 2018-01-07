/*@Description: Search a 2D Matrix
Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:
Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.
For example, Consider the following matrix:
[
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
Given target = 3, return true.
*/

/**
二分法查找，首先利用二分法定位目标值位于哪一行，然后在该行再次利用二分法查找
*/
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty() || matrix[0].empty())
            return false;
        int m = matrix.size(), n = matrix[0].size();
        int left = 0, right = m - 1, mid = 0, row = 0;
        while(left <= right)
        {
            mid = (left + right) / 2;
            //如果目标值在上一行的尾值和当前行的首值之间，则无法确定位于哪一行
            if(matrix[mid][0] <= target && matrix[mid][n - 1] >= target)
            {
                row = mid;
                break;
            }
            else if(matrix[mid][0] > target)
            {
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }    
        }
        //目标值不在任一行之中，直接返回false；不要判断条件也能返回正确结果，但该条件更符合逻辑
        if(left > right)	return false;	
        left = 0, right = n - 1;
        while(left <= right)
        {
            mid = (left + right) / 2;
            if(matrix[row][mid] == target)
                return true;
            else if(matrix[row][mid] < target)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return false;
    }
};

/**
矩阵和数组通过坐标对应，直接进行二分法查找
*/
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty() || matrix[0].empty())
            return false;
        int m = matrix.size(), n = matrix[0].size();
        int left = 0, right = m * n - 1, mid = 0;
        while(left <= right)
        {
            mid = (left + right) / 2;
            if(matrix[mid / n][mid % n] == target)
                return true;
            else if(matrix[mid / n][mid % n] < target)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return false;
    }
};