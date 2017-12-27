/*@Description: Maximum Subarray
Find the contiguous subarray within an array (containing at least one number) which has the largest sum.
For example, given the array [-2,1,-3,4,-1,2,1,-5,4],
the contiguous subarray [4,-1,2,1] has the largest sum = 6.
*/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        int ans = nums[0], sum = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            ans = max(sum, ans);
            sum = max(sum, 0);
        }
        return ans;
    }
};

/**
algorithm that operates on arrays: it starts at the left end (element A[1]) and scans through to the 
right end (element A[n]), keeping track of the maximum sum subvector seen so far. The maximum is 
initially A[0]. Suppose we’ve solved the problem for A[1 … i - 1]; how can we extend that to A[1 … i]? 
The maximum sum in the first i elements is either the maximum sum in the first i - 1 elements (which 
we’ll call MaxSoFar), or it is that of a subvector that ends in position i (which we’ll call MaxEndingHere).
MaxEndingHere is either A[i] plus the previous MaxEndingHere, or just A[i], whichever is larger.

依次遍历所有元素，记录前 i - 1 个元素的最大和值MaxSoFar，以及以第 i 个元素结尾的最大和值MaxEndingHere，并取
两者较大值
*/
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSoFar = nums[0], maxEndingHere = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            maxEndingHere = max(maxEndingHere + nums[i], nums[i]);
            maxSoFar = max(maxSoFar, maxEndingHere);	
        }
        return maxSoFar;
    }
};

/**
和上述方法一致，形式上改成dp算法
*/
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n);  //dp[i] means the maximum subarray ending with A[i];
        dp[0] = nums[0];
        int sum = dp[0];
        for(int i = 1; i < n; i++)
        {
            dp[i] = nums[i] + (dp[i - 1] > 0 ? dp[i - 1] : 0);
            sum = max(sum, dp[i]);
        }
        return sum;
    }
};