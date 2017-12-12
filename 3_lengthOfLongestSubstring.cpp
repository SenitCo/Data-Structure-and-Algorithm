/*@Description
Given a string, find the length of the longest substring without repeating characters.

Examples:

Given "abcabcbb", the answer is "abc", which the length is 3.

Given "bbbbb", the answer is "b", with the length of 1.

Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, 

"pwke" is a subsequence and not a substring.
*/

class Solution1 {
public:
    int lengthOfLongestSubstring(string s) {
        int minLen = std::min((int)s.size(), 1);
        int startSubStr = 0, lenSubStr = minLen, posOfChar = 0;
        int length = s.length(), maxLenSubStr = minLen, thisLenSubStr = minLen;
        while(startSubStr + lenSubStr < length)
        {
            string subStr = s.substr(startSubStr, lenSubStr);
            int index = 0;
            for(index = startSubStr + lenSubStr; index < length;)
            {
                subStr = s.substr(startSubStr, lenSubStr);
                posOfChar = subStr.find(s[index]);
                if(posOfChar != string::npos)
                {
                    startSubStr += posOfChar + 1;
                    thisLenSubStr = lenSubStr;
                    lenSubStr -= posOfChar;
                    break;
                }
                lenSubStr++;
                thisLenSubStr = lenSubStr;
                index =  startSubStr + lenSubStr;
            }
            if(thisLenSubStr > maxLenSubStr)
            {
                maxLenSubStr = thisLenSubStr;
            }
        }
        return maxLenSubStr;        
    }
};


/*************reference****************/
class Solution2 {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> dict(256, -1);
        int maxLen = 0, start = -1;
        for (int i = 0; i != s.length(); i++) 
        {
            if (dict[s[i]] > start)
                start = dict[s[i]];
            dict[s[i]] = i;
            maxLen = max(maxLen, i - start);
        }
        return maxLen;
    }
};