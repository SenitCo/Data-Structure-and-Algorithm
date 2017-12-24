/*@Description: Permutations II
Given a collection of numbers that might contain duplicates, return all possible unique permutations.

For example,
[1,1,2] have the following unique permutations:
[
  [1,1,2],
  [1,2,1],
  [2,1,1]
]
*/

/**
回溯法，增加一个flag数组标志相应元素是否在已有排列中，并排除重复元素的影响
在判断条件(*)中，flag[i]为true则考虑下一个元素；如果是相邻重复元素，则只进行一次纵深排列，而跳过横向迭代；
也就是说对于连续的重复元素{a1, a2, ... ak}，在同一层循环中，只需考虑第一个元素。
*/
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        vector<int> permutation;
        vector<bool> flag(nums.size(), false);
        backtrack(nums, result, permutation, flag);
        return result;
    }
private:
    void backtrack(vector<int>& nums, vector<vector<int>>& result, vector<int>& permutation, vector<bool>& flag)
    {
        if(permutation.size() == nums.size())
        {
            result.push_back(permutation);
            return;
        }
        for(int i = 0; i < nums.size(); i++)
        {         
            if(flag[i] || (i > 0 && nums[i] == nums[i - 1] && !flag[i - 1]))	// (*)
                continue;
            flag[i] = true;
            permutation.push_back(nums[i]);
            backtrack(nums, result, permutation, flag);
            permutation.pop_back();
            flag[i] = false;
        }
    }
};


class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        recursion(nums, result, 0);
        return result;
    }
private:
	//注意第一个参数不是引用，后面的swap操作只对本层以及后续递归有影响
    void recursion(vector<int> nums, vector<vector<int>>& result, int i)	
    {
        if(i == nums.size() - 1)	//只需递归到倒数第二个元素
        {
            result.push_back(nums);
            return;
        }
        for(int j = i; j < nums.size(); j++)
        {
            if(j != i && nums[j] == nums[i])
                continue;
            swap(nums[i], nums[j]);
            recursion(nums, result, i + 1);
        }
   }
};