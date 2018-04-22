/**@Description: House Robber
You are a professional robber planning to rob houses along a street. 
Each house has a certain amount of money stashed, the only constraint stopping you from 
robbing each of them is that adjacent houses have security system connected and it will 
automatically contact the police if two adjacent houses were broken into on the same night.

Given a list of non-negative integers representing the amount of money of each house, 
determine the maximum amount of money you can rob tonight without alerting the police.
*/

int rob(vector<int>& nums) 
{
    int n = nums.size();
    int a = 0, b = 0;
    for(int i = 0; i < n; i++)
    {
        if(i % 2 == 0)
            a = max(a + nums[i], b);
        else
            b = max(a, b + nums[i]);
    }
    return max(a, b);
}

//DP解法
int rob(vector<int>& nums) 
{
    int n = nums.size();
    vector<vector<int>> dp(n + 1, vector<int>(2, 0));
    for(int i = 0; i < n; i++)
    {
        dp[i + 1][0] = max(dp[i][0], dp[i][1]);
        dp[i + 1][1] = dp[i][0] + nums[i];
    }
    return max(dp[n][0], dp[n][1]);
}

//迭代法：常量空间
int rob(vector<int>& nums) 
{
    int n = nums.size();
    int prevNo = 0, prevYes = 0;
    for(int i = 0; i < n; i++)
    {
        int temp = prevNo;
        prevNo = max(prevNo, prevYes);
        prevYes = temp + nums[i];
    }
    return max(prevNo, prevYes);
}