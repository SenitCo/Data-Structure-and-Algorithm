/*@Description: Generate Parentheses
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:

[
  "((()))",
  "(()())",
  "(())()",
  "()(())",
  "()()()"
]
*/

/*
递归解法：left,right分别表示已插入字符串中左右括号的数量
*/
class Solution1 {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        backtrack(result, "", 0, 0, n);
        return result;
    }
    void backtrack(vector<string>& vec, string str, int left, int right, int n)
    {
        if(str.length() == n * 2)
        {
            vec.push_back(str);
            return;
        }
        if(left < n)
            backtrack(vec, str + '(', left + 1, right, n);
        if(right < left)
            backtrack(vec, str + ')', left, right + 1, n);
    }
};

/*
递归解法：n,m分别表示可以插入字符串中的左右括号的剩余数量
*/
class Solution2 {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        addPar(result, "", n, 0);
        return result;
    }
    void addPar(vector<string>& vec, string str, int n, int m)
    {
        if(n == 0 && m == 0)
        {
            vec.push_back(str);
            return;
        }
        if(m > 0)   
            addPar(vec, str + ')', n, m - 1);
        if(n > 0)
            addPar(vec, str + '(', n - 1, m + 1);
    }
};