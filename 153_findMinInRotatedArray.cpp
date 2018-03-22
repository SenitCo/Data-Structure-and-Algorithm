/*@Descripton: Find Minimum in Rotated Sorted Array
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).Find the minimum element.
You may assume no duplicate exists in the array.
*/

/**
二分查找的变体：
如果 nums[mid] < nums[right]，说明右边一定是有序的，令right = mid（不能为mid-1，因为mid可能为最小的数）
如果 nums[mid] >= nums[right]，说明左边一定是有序的，令left = mid + 1（最小值一定在mid的右边）
*/
class Solution {
public:
    int findMin(vector<int>& nums) {
        int size = nums.size();
        int left = 0, right = size - 1, mid = 0;
        while(left < right)
        {
            mid = (left + right) / 2;
            if(nums[mid] < nums[right])
                right = mid;
            else
                left = mid + 1;
        }
        return nums[left];
    }
};