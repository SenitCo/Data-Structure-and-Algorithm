/*@Description: House Robber II
After robbing those houses on that street, the thief has found himself a new place for his thievery 
so that he will not get too much attention. This time, all houses at this place are arranged in a 
circle. That means the first house is the neighbor of the last one. Meanwhile, the security system 
for these houses remain the same as for those in the previous street.

Given a list of non-negative integers representing the amount of money of each house, determine the 
maximum amount of money you can rob tonight without alerting the police.
*/

/*
考虑成环的情况：分两种情况考虑
（1）考虑元素区间[0, n - 1)
（2）考虑元素区间[1, n)
*/

int rob(vector<int>& nums) 
{
    int n = nums.size();
    if(n == 1)
        return nums[0];
    return max(helper(nums, 0, n - 1), helper(nums, 1, n));
}

int helper(vector<int>& nums, int left, int right)
{
    int prevNo = 0, prevYes = 0;
    for(int i = left; i < right; i++)
    {
        int temp = prevNo;
        prevNo = max(prevNo, prevYes);
        prevYes = temp + nums[i];
    }
    return max(prevNo, prevYes);
}

int helper(vector<int>& nums, int left, int right)
{
    int pre = 0, cur = 0;
    for (int i = left; i < right; i++) 
    {
        int temp = max(pre + nums[i], cur);
        pre = cur;
        cur = temp;
    }
    return cur;
}