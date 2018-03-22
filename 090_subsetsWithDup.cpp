/*@Description: Subsets
Given a collection of integers that might contain duplicates, nums, return all possible subsets (the power set).
Note: The solution set must not contain duplicate subsets.
For example,If nums = [1,2,2], a solution is:
[
  [2],
  [1],
  [1,2,2],
  [2,2],
  [1,2],
  []
]
*/

/****************回溯法***************/
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        vector<int> subset;
        backtrack(result, subset, nums, 0);
        return result;
    }
private:
    void backtrack(vector<vector<int>>& result, vector<int>& subset, vector<int>& nums, int begin)
    {
        result.push_back(subset);
        for(int i = begin; i < nums.size(); i++)
        {
            if(i != begin && nums[i - 1] == nums[i])	//跳过重复元素
                continue;
            subset.push_back(nums[i]);
            backtrack(result, subset, nums, i + 1);
            subset.pop_back();
        }
    }
};

/**
迭代法，对于连续k个重复元素，加入子集中的数量可以为[0, 1, ..., k]
*/
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result(1, vector<int>());
        for(int i = 0; i < nums.size();)
        {
            int count = 0;
            while(i + count < nums.size() && nums[i] == nums[i + count])
                count++;
            int previousN = result.size();
            for(int j = 0; j < previousN; j++)
            {
                vector<int> instance = result[j];
                for(int k = 0; k < count; k++)
                {
                    instance.push_back(nums[i]);
                    result.push_back(instance);
                }
            }
            i += count;
        }
        return result;
    }
};

/**
迭代法，如果存在重复元素，则从上一次的size处开始复制子集，添加新元素，直至这一次的size处
*/
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result(1, vector<int>());
        int start = 0, size = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            if(i > 0 && nums[i] == nums[i - 1])
                start = size;
            else
                start = 0;
            size = result.size();
            for(int j = start; j < size; j++)
            {
                result.push_back(result[j]);
                result.back().push_back(nums[i]);
            }
        }
        return result;
    }
};