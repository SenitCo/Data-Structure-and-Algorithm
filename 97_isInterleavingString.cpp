/*@Description: Interleaving String
Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2.
For example, Given: s1 = "aabcc", s2 = "dbbca",
When s3 = "aadbbcbcac", return true.
When s3 = "aadbbbaccc", return false.
*/

/** DP方法
See https://leetcode.com/problems/interleaving-string/discuss/31879
DP table represents if s3 is interleaving at (i+j)th position when s1 is at ith position, 
and s2 is at jth position. 0th position means empty string.
So if both s1 and s2 is currently empty, s3 is empty too, and it is considered interleaving. 
If only s1 is empty, then if previous s2 position is interleaving and current s2 position 
char is equal to s3 current position char, it is considered interleaving. similar idea applies 
to when s2 is empty. when both s1 and s2 is not empty, then if we arrive i, j from i-1, j, then 
if i-1,j is already interleaving and i and current s3 position equal, it s interleaving. If we 
arrive i,j from i, j-1, then if i, j-1 is already interleaving and j and current s3 position 
equal. it is interleaving.
*/
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int m = s1.length(), n = s2.length();
        if(m + n != s3.length())    return false;
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1));
        for(int i = 0; i < m + 1; i++)
        {
            for(int j = 0; j < n + 1; j++)
            {
                if(i == 0 && j == 0)
                    dp[i][j] = true;
                else if(i == 0)
                    dp[i][j] = (dp[i][j - 1] && s2[j - 1] == s3[i + j - 1]);
                else if(j == 0)
                    dp[i][j] = (dp[i - 1][j] && s1[i - 1] == s3[i + j - 1]);
                else
                    dp[i][j] = (dp[i][j - 1] && s2[j - 1] == s3[i + j - 1]) || (dp[i - 1][j] && s1[i - 1] == s3[i + j - 1]);
            }
        }
        return dp[m][n];
    }
};