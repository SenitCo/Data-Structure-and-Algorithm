/*@Description: Combination Sum III
Find all possible combinations of k numbers that add up to a number n, given that only numbers from 1 to 9 can be used and each combination should be a unique set of numbers.
Note: All numbers will be positive integers. The solution set must not contain duplicate combinations.
Example 1: Input: k = 3, n = 7, Output: [[1,2,4]]
Example 2: Input: k = 3, n = 9, Output: [[1,2,6], [1,3,5], [2,3,4]]
*/

/***
如果没限定数字的取值范围，可以将maxVal去掉，并将循环判断条件替换为i<=n
*/
class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> results;
        vector<int> combination;
        int maxVal = 9;
        backtrack(k, maxVal, n, results, combination, 1);
        return results;
    }
    
    void backtrack(const int& k, const int& maxVal, int n, vector<vector<int>>& results, vector<int>& combination, int begin)
    {
        if(combination.size() == k && n == 0)
        {
            results.push_back(combination);
            return;
        }
        for(int i = begin; i <= maxVal && combination.size() < k; i++)
        {
            combination.push_back(i);
            backtrack(k, maxVal, n - i, results, combination, i + 1);
            combination.pop_back();
        }
    }
};