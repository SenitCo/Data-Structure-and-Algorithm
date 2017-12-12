/*@Description: Three Sum
Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? 
Find all unique triplets in the array which gives the sum of zero.
Note: The solution set must not contain duplicate triplets.

For example, given array S = [-1, 0, 1, 2, -1, -4],
A solution set is:
[
  [-1, 0, 1],
  [-1, -1, 2]
]
*/

/*
先取出一个数x，在剩下的数字里面找到两个数字，使得两者和等于(target - x)，那么问题就变成了2Sum；
将数组排序，然后分别从两边向中间遍历，判断是否满足条件。时间复杂度为O(N^2)
*/
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int size = nums.size();
        vector<vector<int>> result;
        if(nums.size() < 3)
            return result;
        if(nums[size-1] < 0 || nums[0] > 0)
            return result;
        if(nums[0] == 0 && nums[size-1] == 0)
            return {{ 0, 0, 0 }};
        for(int i = 0; i < size; i++)
        {
            for(int j = i + 1, k = size - 1; j < k;)
            {
                if(nums[j] + nums[k] == -nums[i]) 
                {
                    vector<int> tmp{nums[i], nums[j], nums[k]};	//此处是有序数组
                    result.push_back(tmp);	
                    k--;
                    j++;
                }
                else if(nums[j] + nums[k] > -nums[i])
                {
                    k--;
                }
                else
                {
                    j++;
                }
            }
        }
        sort(result.begin(), result.end());
        vector<vector<int>>::iterator iter = unique(result.begin(), result.end());
        result.erase(iter, result.end());
        return result;
    }
};


 vector<vector<int>> threeSum(vector<int>& nums) 
 {
        sort(nums.begin(), nums.end());
        int size = nums.size();
        vector<vector<int>> result;
        if(nums.size() < 3)
            return result;
        if(nums[size-1] < 0 || nums[0] > 0)
            return result;
        if(nums[0] == 0 && nums[size-1] == 0)
            return {{ 0, 0, 0 }};
        int currentValue = nums[0];
        for(int i = 0; i < size; i++)
        {
            if(i > 0 && nums[i] == currentValue)    //连续多个相同的数字，只判断第一个
                continue;
            
            for(int j = i + 1, k = size - 1; j < k;)
            {
                if(nums[j] + nums[k] == -nums[i]) 
                {
                    vector<int> tmp{nums[i], nums[j], nums[k]};
                    result.push_back(tmp);
                    k--;
                    j++;
                }
                else if(nums[j] + nums[k] > -nums[i])
                {
                    k--;
                }
                else
                {
                    j++;
                }
            }
            currentValue = nums[i];
        }
        //sort(result.begin(), result.end());
        vector<vector<int>>::iterator iter = unique(result.begin(), result.end());  //最后得到的元组都是有序的，无需另外排序
        result.erase(iter, result.end());
        return result;
    }