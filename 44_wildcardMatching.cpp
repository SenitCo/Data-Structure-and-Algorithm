/*@Description: Wildcard Matching
mplement wildcard pattern matching with support for '?' and '*'.

'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).

The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(const char *s, const char *p)

Some examples:
isMatch("aa","a") → false
isMatch("aa","aa") → true
isMatch("aaa","aa") → false
isMatch("aa", "*") → true
isMatch("aa", "a*") → true
isMatch("ab", "?*") → true
isMatch("aab", "c*a*b") → false
*/

/**
（1）若两字符串中的字符匹配则索引均前进；
（2）若模式串中出现'*'，则记录'*'号位置 starIdx=pIdx，以及原串的当前位置 match=sIdx；
（3）若当前字符不匹配，且模式串当前字符不为'*'，而上一个字符为'*'，则模式串中待比较字符为'*'号下一个，
	原串字符索引则相对match位置继续前进；
（4）若以上条件均不满足，则两字符串不匹配，返回false；
（5）原串字符遍历结束后，判断模式串是否结束或者剩余字符是否均为'*'
*/
class Solution {
public:
    bool isMatch(string s, string p) {
        int sIdx = 0, pIdx = 0, starIdx = -1, match = 0;
        while(sIdx < s.length())
        {
            if(pIdx < p.length() && (s[sIdx] == p[pIdx] || p[pIdx] == '?'))		// (1)	
            {
                sIdx++;
                pIdx++;
            }
            else if(pIdx < p.length() && p[pIdx] == '*')	// (2)
            {
                starIdx = pIdx;
                pIdx++;
                match = sIdx;
            }
            else if(starIdx != -1)		// (3)
            {
                pIdx = starIdx + 1;
                match++;
                sIdx = match;
            }
            else 						// (4)
                return false;
        }
        while(pIdx < p.length() && p[pIdx] == '*')		// (5)
            pIdx++;
        return pIdx == p.length();
    }
};