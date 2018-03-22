/*@Description: Substring with Concatenation of All Words
link: https://leetcode.com/problems/substring-with-concatenation-of-all-words/description/

You are given a string, s, and a list of words, words, that are all of the same length.
Find all starting indices of substring(s) in s that is a concatenation of each word in words 
exactly once and without any intervening characters.

For example, given:
s: "barfoothefoobarman"
words: ["foo", "bar"]

You should return the indices: [0,9].
(order does not matter).
*/

/*
Using an unordered_map<string, int> counts to record the expected times of each word and another 
unordered_map<string, int> seen to record the times we have seen. Then checking for every possible 
position of i. Once we meet an unexpected word or the times of some word is larger than its expected 
times, we stop the check. If we finish the check successfully, push i to the result indexes.
*/
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        unordered_map<string, int>counts;
        for(string word : words)
        {
            counts[word]++;
        }
        int length = s.length(), num = words.size(), len = words[0].length();
        vector<int> result;
        for(int i = 0; i < length - num * len + 1; i++)
        {
            int j = 0;
            unordered_map<string, int> seen;
            for(; j < num; j++)
            {
                string word = s.substr(i + j * len, len);
                if(counts.find(word) != counts.end())
                {
                    seen[word]++;
                    if(seen[word] > counts[word])
                        break;
                }
                else
                    break;
            }
            if(j == num)
                result.push_back(i);
        }
        return result;
    }
};