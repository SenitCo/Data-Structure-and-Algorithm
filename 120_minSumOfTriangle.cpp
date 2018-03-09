/*@Description: Triangle
Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.
For example, given the following triangle
[
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]
The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).
Note: Bonus point if you are able to do this using only O(n) extra space, where n is the total number of rows in the triangle.
*/

/**
DP算法：从下往上遍历，对当前的某一行取值，选择其下一行相邻的两个累加路径和中较小的一个，
进行求和并将结果作为当前行当前位置的最短路径和。
*/
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if(triangle.empty())    return 0;
        int size = triangle.size(), minSum = 0;
        vector<int> pathSum(triangle[size - 1].begin(), triangle[size - 1].end());
        for(int i = size - 2; i >= 0; i--)
        {
            for(int j = 0; j < i + 1; j++)
            {
                pathSum[j] = triangle[i][j] + min(pathSum[j], pathSum[j + 1]);
            }
        }
        return pathSum[0];
    }
};