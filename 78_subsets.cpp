/*@Description: Subsets
Given a set of distinct integers, nums, return all possible subsets (the power set).
Note: The solution set must not contain duplicate subsets.
For example, If nums = [1,2,3], a solution is:
[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]
*/

/********回溯法*******/
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> subset;
        backtrack(result, subset, nums, 0);
        return result;
    }
private:
    void backtrack(vector<vector<int>>& result, vector<int>& subset, vector<int>& nums, int begin)
    {
        result.push_back(subset);	//无需判断条件，每次递归都是一个子集
        for(int i = begin; i < nums.size(); i++)
        {
            subset.push_back(nums[i]);
            backtrack(result, subset, nums, i + 1);
            subset.pop_back();
        }
    }
};

/**
位操作法（Bit manipulation），一共2^n种情况，正好对应n位二进制数的所有0、1组合情况
*/
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int elemNum = nums.size(), setNum = pow(2, elemNum);
        vector<vector<int>> result(setNum);
        for(int i = 0; i < elemNum; i++)
        {
            for(int j = 0; j < setNum; j++)
            {
                if((j >> i) & 1)
                    result[j].push_back(nums[i]);
            }
        }
        return result;
    }
};