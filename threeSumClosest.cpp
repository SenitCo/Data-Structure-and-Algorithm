/*@Description: 3Sum Closest
Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. 
Return the sum of the three integers. You may assume that each input would have exactly one solution.

For example, given array S = {-1 2 1 -4}, and target = 1.
The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
*/

/*
先取出一个数x，在剩下的数字里面找到两个数字，使得三者和与target的距离最小
将数组排序，然后分别从两边向中间遍历，计算最小距离。时间复杂度为O(N^2)
*/

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int size = nums.size();
        int result, dist, minDist = INT_MAX;
        
        for(int i = 0; i < size; i++)
        {
            for(int j = i + 1, k = size - 1; j < k;)
            {
                dist = nums[i] + nums[j] + nums[k] - target;
                if(abs(dist) < minDist)
                {
                    minDist = abs(dist);
                    result = nums[i] + nums[j] + nums[k];
                }
                if(dist == 0)
                    return target;
                else if(dist > 0) 
                {
                    k--;
                }
                else 
                {
                    j++;
                }
            }
        }
        return result;
    }
};