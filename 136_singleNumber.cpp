/*@Description: Single Number
Given an array of integers, every element appears twice except for one. Find that single one.
Note: Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
*/

/**
位操作：最大次数为两次，使用1位即可表示，即采用一个int型变量存储数组的元素和，在累加过程中除以2取余，
每一位的变化过程为0->1->0(2/0)，利用异或操作实现
*/
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ones = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            ones = ones ^ nums[i];
        }
        return ones;
    }
};