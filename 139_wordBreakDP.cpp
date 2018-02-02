/*@Description: Word Break
Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, 
determine if s can be segmented into a space-separated sequence of one or more dictionary 
words. You may assume the dictionary does not contain duplicate words.
For example, given s = "leetcode", dict = ["leet", "code"].
Return true because "leetcode" can be segmented as "leet code".
*/

/**
DP解法：定义一个数组dp[]，dp[i]为true表示一个有效的单词或单词序列和字符串s的前i个字符匹配
*/
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordSet;
        for(auto word : wordDict)
            wordSet.insert(word);   //将所有元素移至hashset中，这样在一轮搜索过程中时间复杂度为O(1)
        vector<bool> dp(s.length() + 1, false);
        dp[0] = true;
        for(int i = 1; i <= s.length(); i++)
        {
            for(int j = i - 1; j >= 0; j--) //反向遍历可能会更快
            {
                if(dp[j])   //dp[j]为true且子串s.substr(j, i-j)在word集合中，则dp[i]为true
                {
                    string str = s.substr(j, i - j);
                    if(wordSet.find(str) != wordSet.end())
                    {
                        dp[i] = true;
                        break;
                    }
                }
            }
        }
        return dp[s.length()];
    }
};