/*@Description: Jump Game
Given an array of non-negative integers, you are initially positioned at the first index of the array.
Each element in the array represents your maximum jump length at that position.
Determine if you are able to reach the last index.

For example:
A = [2,3,1,1,4], return true.
A = [3,2,1,0,4], return false.
*/

/**
1. 能跳到位置i的条件：i<=maxIndex。
2. 一旦跳到i，则maxIndex = max(maxIndex, i+nums[i])。
3. 能跳到最后一个位置n-1的条件是：maxIndex >= n-1
*/
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxIndex = 0, size = nums.size();
        for(int i = 0; i < size; i++)
        {
            if(i > maxIndex || maxIndex >= size - 1)
                break;
            maxIndex = max(maxIndex, nums[i] + i);
        }
        return maxIndex >= size - 1; 
    }
};

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int i = 0, n = nums.size();
        for (int reach = 0; i < n && i <= reach; ++i)
            reach = max(i + nums[i], reach);
        return i == n;
    }
};