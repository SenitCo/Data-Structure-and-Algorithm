/*@Description: Search for a Range
Given an array of integers sorted in ascending order, find the starting and ending position of a given target value.
Your algorithm's runtime complexity must be in the order of O(log n).
If the target is not found in the array, return [-1, -1].

For example,
Given [5, 7, 7, 8, 8, 10] and target value 8,
return [3, 4].
*/

/*********二分法查找，找到目标值后前后搜索边界**********/
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int size = nums.size();
        if(size < 1 || target < nums[0] || target > nums[size - 1])
            return vector<int>({ -1, -1 });
        int left = 0, mid = 0, right = size - 1;
        vector<int> result;
        while(left <= right)
        {
            mid = (left + right) / 2;
            if(nums[mid] == target)
            {
                int j = mid - 1;
                while(j >= 0 && nums[j] == target)    j--;
                result.push_back(j + 1);
                j = mid + 1;
                while(j < size && nums[j] == target)    j++;
                result.push_back(j - 1);
                return result;
            }
            else if(nums[mid] > target)
            {
                right = mid - 1;
            }
            else 
            {
                left = mid + 1;
            }
        }
        return vector<int>({-1, -1});
    }
};