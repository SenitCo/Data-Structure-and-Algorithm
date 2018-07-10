/*@Description: Wildcard Matching
Implement wildcard pattern matching with support for '?' and '*'.

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


/**
DP方法：如果s[0:i)匹配p[0:j)，DP[i][j]=true，否则DP[i][j]=false
(1) DP[i][j] = DP[i - 1][j - 1] && (s[i - 1] == p[j - 1] || p[j - 1] == '?'), if p[j - 1] != '*';
(2) DP[i][j] = DP[i][j - 1] || DP[i - 1][j], if p[j - 1] == '*'.
*/
class Solution {
public:
    bool isMatch(string s, string p) {
        int lenS = s.length(), lenP = p.length();
        vector<vector<bool>> match(lenS + 1, vector<bool>(lenP + 1, false));
        match[0][0] = true;
        for(int j = 0; j < lenP && p[j] == '*'; j++)	//模式串中起始字符为连续的'*'
        {
            match[0][j + 1] = true;
        }
        for(int i = 0; i < lenS; i++)
        {
            for(int j = 0; j < lenP; j++)
            {
                if(s[i] == p[j] || p[j] == '?')				// (1)
                    match[i + 1][j + 1] = match[i][j];
                else if(p[j] == '*')						// (2)
                    match[i + 1][j + 1] = match[i][j + 1] || match[i + 1][j];
                else
                    match[i + 1][j + 1] = false;
            }
        }
        
        return match[lenS][lenP];
    }
};