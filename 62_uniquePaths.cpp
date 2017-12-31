/*@Description: 
A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).
The robot can only move either down or right at any point in time. The robot is trying to reach 
the bottom-right corner of the grid (marked 'Finish' in the diagram below).
How many possible unique paths are there?

Note: m and n will be at most 100.
*/

/**
DP解法：由于只能向下或向右移动，第一行第一列均为1，且满足关系式dp[i][j] = dp[i - 1][j] + dp[i][j - 1]
*/
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for(int i = 1; i < m + 1; i++)
            dp[i][1] = 1;
        for(int j = 1; j < n + 1; j++)
            dp[1][j] = 1;
        for(int i = 2; i < m + 1; i++)
        {
            for(int j = 2; j < n + 1; j++)
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
        return dp[m][n];
    }
};

/**
DP解法的简化版本，无需考虑为0的情况
*/
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int> > path(m, vector<int> (n, 1));
        for (int i = 1; i < m; i++)
            for (int j = 1; j < n; j++)
                path[i][j] = path[i - 1][j] + path[i][j - 1];
        return path[m - 1][n - 1];
    }
};

/**
公式解法：从(1, 1)到(m, n)一共要走 N = (m-1)+(n-1) = m+n-2 步，其中往下走 k = (m-1) 步，
因此一共有Combination(N, k) = n! / (k!(n - k)!)种组合
*/
class Solution {
public:
    int uniquePaths(int m, int n) {
        int N = n + m - 2;// how much steps we need to do
        int k = m - 1; // number of steps that need to go down
        double res = 1;
        // here we calculate the total possible path number 
        // Combination(N, k) = n! / (k!(n - k)!)
        // reduce the numerator and denominator and get
        // C = ( (n - k + 1) * (n - k + 2) * ... * n ) / k!
        for (int i = 1; i <= k; i++)
            res = res * (N - k + i) / i;
        return (int)res;
    }
};