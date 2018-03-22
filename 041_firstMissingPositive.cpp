/*@Description: First Missing Positive
Given an unsorted integer array, find the first missing positive integer.

For example,
Given [1,2,0] return 3,
and [3,4,-1,1] return 2.

Your algorithm should run in O(n) time and uses constant space.
*/

/**
交换数组元素，使得数组中第i位存放数值(i+1)。最后遍历数组，寻找第一个不符合此要求的元素，返回其下标。
整个过程需要遍历两次数组，复杂度为O(n)
扫描数组中每个数：
1. 如果A[i]<1或者A[i]>n。说明A[i]一定不是first missing positive。跳过
2. 如果A[i] = i+1，说明A[i]已经在正确的位置，跳过
3. 如果A[i]!=i+1，且0<A[i]<=n，应当将A[i]放到A[A[i]-1]的位置，所以可以交换两数。
这里注意，当A[i] = A[A[i]-1]时会陷入死循环。这种情况下直接跳过。
*/
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int i = 0, size = nums.size();
        while(i <size)
        {
            if(nums[i] != i + 1 && nums[i] > 0 && nums[i] <= size && nums[i] != nums[nums[i] - 1])
                swap(nums[i], nums[nums[i] - 1]);
            else
                i++;
        }
        for(i = 0; i < size; i++)
        {
            if(nums[i] != i + 1)
                return i + 1;
        }
        return size + 1;
    }
};


class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n; ++i)
            while(nums[i] > 0 && nums[i] <= n && nums[nums[i] - 1] != nums[i])
                swap(nums[i], nums[nums[i] - 1]);
        
        for(int i = 0; i < n; ++i)
            if(nums[i] != i + 1)
                return i + 1;
        
        return n + 1;
    }
};