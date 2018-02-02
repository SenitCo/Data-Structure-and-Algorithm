/*@Description: Word Break II
Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, add spaces in s 
to construct a sentence where each word is a valid dictionary word. You may assume the dictionary does not 
contain duplicate words.
Return all such possible sentences.
For example, given s = "catsanddog", dict = ["cat", "cats", "and", "sand", "dog"].
A solution is ["cats and dog", "cat sand dog"].
*/

//递归回溯
class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string, vector<string>> mp;
        unordered_set<string> dict;
        for(auto word : wordDict)
            dict.insert(word);
        return wordBreakRecur(s, dict, mp);
    }
private:
    vector<string> wordBreakRecur(string s, unordered_set<string>& dict, unordered_map<string, vector<string>>& mp)
    {
        if(mp.count(s)) return mp[s];
        vector<string> result;
        if(dict.count(s))
            result.push_back(s);
        
        for(int i = 1; i < s.length(); i++)
        {
            string word = s.substr(i);
            if(dict.count(word))
            {
                string remain = s.substr(0, i);
                vector<string> prev = wordBreakRecur(remain, dict, mp);
                combine(word, prev);
                result.insert(result.end(), prev.begin(), prev.end());
            }
        }
        mp[s] = result;
        return result;
    }
    
    void combine(string word, vector<string>& prev)
    {
        for(int i = 0; i < prev.size(); i++)
            prev[i] += " " + word;
    }
};

