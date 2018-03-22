/*@Description: Next Permutation
Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.
If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).
The replacement must be in-place, do not allocate extra memory.

Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
1,2,3 → 1,3,2
3,2,1 → 1,2,3
1,1,5 → 1,5,1
*/
/**
实现数组的下一个排列：先找到第一个降序的数字，nums[i+1] > nums[i]，然后从后往前找到第一个大于nums[i]的数，记为nums[j]，
交换nums[i]与nums[j]的值，并翻转 i 后面的元素。
*/
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int size = nums.size();
        if(size < 2)
            return;
        int i = 0, j = 0;
        for(i = size - 1; i > 0; i--)
            if(nums[i] > nums[i - 1])   break;
        if(i == 0)
        {
            reverse(nums.begin(), nums.end());
            return;
        }
        for(j = size - 1; j >= i; j--)
            if(nums[j] > nums[i - 1])   break;
        
        swap(nums[i - 1], nums[j]);
        reverse(nums.begin() + i, nums.end());       
    }
};

void nextPermutation(vector<int>& nums) 
{
    next_permutation(begin(nums), end(nums));
}