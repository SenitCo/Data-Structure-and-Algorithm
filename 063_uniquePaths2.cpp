/*@Description: Unique Paths II
Follow up for "Unique Paths":
Now consider if some obstacles are added to the grids. How many unique paths would there be?
An obstacle and empty space is marked as 1 and 0 respectively in the grid.
For example,
There is one obstacle in the middle of a 3x3 grid as illustrated below.
[
  [0,0,0],
  [0,1,0],
  [0,0,0]
]
The total number of unique paths is 2.
Note: m and n will be at most 100.
*/

/**
有障碍物的位置有效路径数为0，第一行第一列需特殊处理，只要某点存在障碍物，则该点及该点之后取值均为0
*/
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if(obstacleGrid.empty())
            return 0;
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<vector<int>> path(m, vector<int>(n, 1));
        for(int i = 0; i < m; i++)
        {   
            if(obstacleGrid[i][0] == 1)
            {
                for(; i < m; i++)
                    path[i][0] = 0;
                break;
            }
        }
        for(int j = 0; j < n; j++)
        {   
            if(obstacleGrid[0][j] == 1)
            {
                for(; j < n; j++)
                    path[0][j] = 0;
                break;
            }
        }
        for(int i = 1; i < m; i++)
        {
            for(int j = 1; j < n; j++)
            {
                if(obstacleGrid[i][j] == 1)
                    path[i][j] = 0;
                else
                    path[i][j] = path[i][j - 1] + path[i - 1][j];
            }
        }
        return path[m - 1][n - 1];
    }
};

/**
每次考虑一行的dp取值，并累加更新
*/
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if(obstacleGrid.empty())
            return 0;
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<int> path(n, 0);
        path[0] = 1;
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(obstacleGrid[i][j] == 1)
                    path[j] = 0;
                else if(j > 0)
                    path[j] += path[j - 1];
            }
        }
        return path[n - 1];
    }
};

/**
增加额外的第0行第0列，并使dp[0][1]取值为1，然后判断有无障碍物来更新dp值
*/
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if(obstacleGrid.empty())
            return 0;
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        dp[0][1] = 1;
        for(int i = 1 ; i < m + 1; ++i)
            for(int j = 1 ; j < n + 1; ++j)
                if(!obstacleGrid[i - 1][j - 1])
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        return dp[m][n];
    }
};