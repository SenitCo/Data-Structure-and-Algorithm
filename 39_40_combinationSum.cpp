/*@Description: Combination Sum
Given a set of candidate numbers (C) (without duplicates) and a target number (T), find all unique combinations 
in C where the candidate numbers sums to T. The same repeated number may be chosen from C unlimited number of times.

Note:
All numbers (including target) will be positive integers.
The solution set must not contain duplicate combinations.
For example, given candidate set [2, 3, 6, 7] and target 7, 
A solution set is: 
[
  [7],
  [2, 2, 3]
]
*/

/*Combination Sum问题采用回溯法可解决*/

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> result;
        vector<int> combination;
        search(candidates, combination, result, target, 0);
        return result;
    }
private:
    void search(vector<int>& candidates, vector<int>& combination, vector<vector<int>>& result, int target, int begin)
    {
        if(target == 0)
        {
            result.push_back(combination);
            return;
        }
        for(int i = begin; i < candidates.size() && target >= candidates[i]; i++)
        {
            combination.push_back(candidates[i]);
            search(candidates, combination, result, target - candidates[i], i);		//不是 i + 1 ,可重复利用同一元素
            combination.pop_back();
        }
    }
};


/*@Description: Combination Sum II
Given a collection of candidate numbers (C) and a target number (T), find all unique combinations in C where 
the candidate numbers sums to T. Each number in C may only be used once in the combination.

Note:
All numbers (including target) will be positive integers.
The solution set must not contain duplicate combinations.
For example, given candidate set [10, 1, 2, 7, 6, 1, 5] and target 8, 
A solution set is: 
[
  [1, 7],
  [1, 2, 5],
  [2, 6],
  [1, 1, 6]
]
*/

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> result;
        vector<int> combination;
        search(candidates, combination, result, target, 0);
        return result;
    }
private:
    void search(vector<int>& candidates, vector<int>& combination, vector<vector<int>>& result, int target, int begin)
    {
        if(target == 0)
        {
            result.push_back(combination);
            return;
        }
        for(int i = begin; i < candidates.size() && target >= candidates[i]; i++)
        {
            if(i == begin || candidates[i] != candidates[i - 1]) 			//跳过重复元素
            {
                combination.push_back(candidates[i]);
                search(candidates, combination, result, target - candidates[i], i + 1);		//每个元素只可用一次
                combination.pop_back();
            }
        }
    }
};