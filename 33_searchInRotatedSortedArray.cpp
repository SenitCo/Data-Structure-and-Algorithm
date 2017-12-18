/*@Description: Search in Rotated Sorted Array
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
You are given a target value to search. If found in the array return its index, otherwise return -1.
You may assume no duplicate exists in the array.
*/

/**
二分查找的变体：由于序列存在旋转的情况，需要做进一步的判断
（1）如果 target == nums[mid]，返回mid
（2）如果 nums[mid] < nums[right]，说明右边一定是有序的；然后判断是否有 nums[mid] < target <= nums[right]，
	若是则 left = mid + 1，否则 right = mid - 1
（3）如果 nums[mid] >= nums[right]，说明左边一定是有序的；然后判断是否有 nums[left] <= target < nums[mid]，
	若是则 right = mid - 1，否则 left = mid + 1
时间复杂度为O(n)，空间复杂度为O(1)，前提条件是没有重复元素
*/
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int size = nums.size();
        if(size == 0)
            return -1;
        int left = 0, mid = 0, right = size - 1;
        while(left <= right)
        {
            mid = (left + right) / 2;
            if(nums[mid] == target)
                return mid;
            else if(nums[mid] < nums[right])
            {
                if(nums[mid] < target && nums[right] >= target)
                    left = mid + 1;
                else
                    right = mid - 1;
            }
            else
            {
                if(nums[mid] > target && nums[left] <= target)
                    right = mid - 1;
                else
                    left = mid + 1;
            }
        }
        return -1;
    }
};