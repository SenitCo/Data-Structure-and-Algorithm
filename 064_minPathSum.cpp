/*@Description: Minimum Path Sum
Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes 
the sum of all numbers along its path.
Note: You can only move either down or right at any point in time.
Example 1:
[[1,3,1],
 [1,5,1],
 [4,2,1]]
Given the above grid map, return 7. Because the path 1→3→1→1→1 minimizes the sum.
*/

/**
DP方法：由于只能向右或向下移动，最短路径满足关系式path[i][j] = min(path[i - 1][j], path[i][j - 1]) + grid[i - 1][j - 1]
*/
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if(grid.empty())    return 0;
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> path(m + 1, vector<int>(n + 1, INT_MAX));	//INT_MAX用于解决左、上边界的取值
        path[0][1] = 0;
        for(int i = 1; i < m + 1; i++)
        {
            for(int j = 1; j < n + 1; j++)
            {
                path[i][j] = min(path[i - 1][j], path[i][j - 1]) + grid[i - 1][j - 1];
            }
        }
        return path[m][n];
    }
};

/**
上述方法的空间简化版本，只需要O(m)的线性空间
*/
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if(grid.empty())    return 0;
        int m = grid.size(), n = grid[0].size();
        vector<int> cur(m, grid[0][0]);
        for (int i = 1; i < m; i++)
            cur[i] = cur[i - 1] + grid[i][0]; 
        for (int j = 1; j < n; j++) {
            cur[0] += grid[0][j]; 
            for (int i = 1; i < m; i++)
                cur[i] = min(cur[i - 1], cur[i]) + grid[i][j];
        }
        return cur[m - 1];
    }
};