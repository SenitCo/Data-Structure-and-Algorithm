/*@Description: Search in Rotated Sorted Array II
Follow up for "Search in Rotated Sorted Array":
What if duplicates are allowed?
Would this affect the run-time complexity? How and why?
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
Write a function to determine if a given target is in the array.
The array may contain duplicates.
*/

/**
重复元素的存在可能导致中间和边缘相等的情况，这样就丢失了哪边有序的信息，因为哪边都有可能是有序的结果。
假设原数组是{1,2,3,3,3,3,3}，那么旋转之后有可能是{3,3,3,3,3,1,2}，或者{3,1,2,3,3,3,3}，这样判断左边缘
和中心的时候都是3，如果要寻找1或者2，并不知道应该跳向哪一半。解决的办法只能是对边缘移动一步，直到边缘
和中间不再相等或者相遇，这就导致了会有不能切去一半的可能。所以最坏情况（比如全部都是一个元素，或者只有
一个元素不同于其他元素，而且就在最后一个）就会出现每次移动一步，总共是n步，算法的时间复杂度变成O(n)
*/
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int size = nums.size();
        if(size == 0)
            return false;
        int left = 0, mid = 0, right = size - 1;
        while(left <= right)
        {
            mid = (left + right) / 2;
            if(nums[mid] == target)
                return true;
            else if(nums[mid] > nums[left]) 	//注意此处是和最左边元素(left)比较，对应的else就是left++
            {   								//如果是和right比较，那就应该是right--
                if(nums[mid] > target && nums[left] <= target)
                    right = mid - 1;
                else
                    left = mid + 1;
            }
            else if(nums[mid] < nums[left])
            {
                if(nums[mid] < target && nums[right] >= target)
                    left = mid + 1;
                else
                    right = mid - 1;
            }
            else
                left++;
        }
        return false;
    }
};