/*Description: Longest Common Prefix
Write a function to find the longest common prefix string amongst an array of strings
*/
/*求字符串数组的最长公共前缀*/
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int index = 0, maxLen = 0;
        if(strs.size() == 0)
            return "";
        if(strs.size() == 1)
            return strs[0];
        int minLen = strs[0].length(), len = 0;
        for(int i = 1; i < strs.size(); i++)
        {
            len = strs[i].length();
            if(len < minLen )
                minLen = len;          
        }
        int i = 0, j = 0;
        for(i = 0; i < minLen; i++)
        {
            for(j = 1; j < strs.size(); j++)
            {
                if(strs[0][i] != strs[j][i])
                    break;
            }
            if(j < strs.size())
                break;
        }
        return strs[0].substr(0, i);
    }
};