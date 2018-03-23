/*@Description: Find Minimum in Rotated Sorted Array II
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
Find the minimum element. The array may contain duplicates.
*/

/**
二分查找的变体：
（1）如果 nums[mid] < nums[right]，说明右边一定是有序的，令right = mid（不能为mid-1，因为mid可能为最小的数）
（2）如果 nums[mid] > nums[right]，说明左边一定是有序的，令left = mid + 1（最小值一定在mid的右边）
（3）如果 nums[mid] == nums[right]，可能出现以下情况，唯一能确定的是最小值一定在right左边，因此right--
    [1, 3, 3]
    [3, 3, 3, 1, 3]
    [3, 1, 3, 3, 3]
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
            else if(nums[mid] > nums[right])
                left = mid + 1;
            else
                right--;
        }
        return nums[left];
    }
};