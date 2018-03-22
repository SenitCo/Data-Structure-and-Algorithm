/*@Description: Combinations
Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.
For example, If n = 4 and k = 2, a solution is:
[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]
*/

/*
组合问题中使用的经典方法：回溯法
*/
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        vector<int> combination;
        backtrack(result, combination, n, k, 0, 0);
        return result;
    }
private:
    void backtrack(vector<vector<int>>& result, vector<int>& combination, int n, int k, int begin, int num)
    {
        if(num == k)
        {
            result.push_back(combination);
            return;
        }
        for(int i = begin; i < n; i++)
        {
            combination.push_back(i + 1);
            backtrack(result, combination, n, k, i + 1, num + 1);
            combination.pop_back();
        }
    }   
};

/**
上述方法的简化版本，无需另外定义一个计数变量 num ，并将循环条件换为 i < n - k + 1，因为一个组合中必须有 k 个值
*/
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        vector<int> combination;
        backtrack(result, combination, n, k, 0);
        return result;
    }
private:
    void backtrack(vector<vector<int>>& result, vector<int>& combination, int n, int k, int begin)
    {
        if(k == 0)
        {
            result.push_back(combination);
            return;
        }
        for(int i = begin; i < n - k + 1; i++)
        {
            combination.push_back(i + 1);
            backtrack(result, combination, n, k - 1, i + 1);
            combination.pop_back();
        }
    }  
};

/**
组合迭代公式：C(n, k) = C(n - 1, k - 1) + C(n - 1, k)，n被选中和n没被选中两种情况
*/
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int> > res,res1;      
        if(k==n || k==0)
        {
            vector<vector<int> > res2;
            vector<int> curr;
            for(int i=1;i<=k;i++)
                curr.push_back(i);
            res2.push_back(curr);
            return res2;
        }
        
        res = combine(n-1,k-1);
        
        for(auto itr=res.begin();itr!=res.end();itr++)
        {
            itr->push_back(n);
        }
        
        res1 = combine(n-1,k);
        
        res.insert(res.end(),res1.begin(),res1.end());
        return res;
    }
    
};

//See https://leetcode.com/problems/combinations/discuss/26992
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
		int i = 0;
		vector<int> p(k, 0);
		while (i >= 0) {
			p[i]++;
			if (p[i] > n) --i;
			else if (i == k - 1) result.push_back(p);
			else {
			    ++i;
			    p[i] = p[i - 1];
			}
		}
		return result;
    }  
};