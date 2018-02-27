/*@Description: Palindrome Partitioning
Given a string s, partition s such that every substring of the partition is a palindrome.
Return all possible palindrome partitioning of s.
For example, given s = "aab", return
[
  ["aa","b"],
  ["a","a","b"]
]
*/

//回溯法
class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> cut;
        backtrack(result, cut, s, 0);
        return result;
    }
private:
    void backtrack(vector<vector<string>>& result, vector<string>& cut, string& s, int begin)
    {
        if(begin == s.length())
        {
            result.push_back(cut);
            return;
        }
        for(int i = begin; i < s.size(); i++)
        {
            if(isPalindrome(s, begin, i))
            {
                cut.push_back(s.substr(begin, i - begin + 1));
                backtrack(result, cut, s, i + 1);
                cut.pop_back();
            }
            
        }
    }
    
    bool isPalindrome(string& s, int start, int end)
    {
        while(start < end)
        {
            if(s[start++] != s[end--])
                return false;
        }
        return true;
    }
};