/*@Description: Palindrome Partitioning II
Given a string s, partition s such that every substring of the partition is a palindrome.
Return the minimum cuts needed for a palindrome partitioning of s.
For example, given s = "aab", Return 1 since the palindrome partitioning ["aa","b"] could be produced using 1 cut.
*/

//DP算法
class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        vector<int> cut(n + 1, 0);
        for(int i = 0; i < n + 1; i++)
            cut[i] = i - 1;     //初始化dp值
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; i - j >= 0 && i + j < n && s[i - j] == s[i + j]; j++)
                cut[i + j + 1] = min(cut[i + j + 1], cut[i - j] + 1);   //奇数长度的回文序列
            for(int j = 1; i - j + 1 >= 0 && i + j < n && s[i - j + 1] == s[i + j]; j++)
                cut[i + j + 1] = min(cut[i + j + 1], cut[i - j + 1] + 1);   //偶数长度的回文序列
        }
        return cut[n];
    }
};

//dp[i + 1]记录长度为i的序列的最小分割次数，isPal[i][j]表示s[i...j]是否为回文序列
class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        vector<int> dp(n + 1, 0);
        for(int i = 0; i < n + 1; i++)
            dp[i] = i - 1;
        vector<vector<bool>> isPal(n, vector<bool>(n, false));
        for(int right = 0; right < n; right++)
        {
            for(int left = 0; left <= right; left++)
            {
                if(s[left] == s[right] && (right - left < 2 || isPal[left + 1][right - 1]))
                {
                    isPal[left][right] = true;
                    if(left == 0)
                        dp[right + 1] = 0;
                    else
                        dp[right + 1] = min(dp[right + 1], dp[left] + 1);
                }
            }
        }
        return dp[n];
    }
};