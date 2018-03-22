/*@Description: Edit Distance
Given two words word1 and word2, find the minimum number of steps required to convert word1 to word2. 
(each operation is counted as 1 step.)
You have the following 3 operations permitted on a word:
a) Insert a character
b) Delete a character
c) Replace a character
*/

/**
DP算法：令dp[i][j]表示将word1[0...i-1]转换为word2[0...j-1]所需的最小转换次数
1. i = 0, dp[0][j] = j; j = 0, dp[i][0] = i
2. word1[i - 1] = word2[j - 1]: dp[i][j] = dp[i - 1][j - 1]
3. word1[i - 1] != word2[j - 1]，则考虑以下三种情况：
(1) word1[i - 1]替换为word2[j - 1]: dp[i][j] = dp[i - 1][j - 1] + 1
(2) 删除word1[i - 1], word1[0...i - 2] = word2[0...j - 1]: dp[i][j] = dp[i - 1][j] + 1
(3) 插入Word2[j - 1], word1[0...i - 1] + word2[j - 1] = word2[0...j - 1]: dp[i][j] = dp[i][j - 1] + 1
*/
class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size(), n = word2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for(int i = 1; i < m + 1; i++)
            dp[i][0] = i;
        for(int j = 1; j < n + 1; j++)
            dp[0][j] = j;
        for(int i = 1; i < m + 1; i++)
        {
            for(int j = 1; j < n + 1; j++)
            {
                if(word1[i - 1] == word2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1];
                else
                    dp[i][j] = min(dp[i - 1][j - 1] + 1, min(dp[i - 1][j] + 1, dp[i][j - 1] + 1));
            }
        }
        return dp[m][n];
    }
};

/**
DP算法的简化版本，只需O(m)存储空间
*/
class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size(), n = word2.size();
        vector<int> cur(m + 1, 0);
        for(int i = 0; i < m + 1; i++)
            cur[i] = i;
        for(int j = 1; j < n + 1; j++)
        {
            cur[0] = j;
            int pre = 0, tmp = 0;
            for(int i = 1; i < m + 1; i++)
            {
                tmp = cur[i];
                cur[i] = min(pre, min(cur[i], cur[i - 1]));
                pre = tmp;
            }
        }
    }
};

