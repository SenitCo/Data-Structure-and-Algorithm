/*@Description: Regular Expression Matching
Implement regular expression matching with support for '.' and '*'.

'.' Matches any single character.
'*' Matches zero or more of the preceding element.

The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(const char *s, const char *p)

Some examples:
isMatch("aa","a") → false
isMatch("aa","aa") → true
isMatch("aaa","aa") → false
isMatch("aa", "a*") → true
isMatch("aa", ".*") → true
isMatch("ab", ".*") → true
isMatch("aab", "c*a*b") → true
*/

/*递归解法一
- 若p为空，若s也为空，返回true，反之返回false
- 若p的长度为1，若s长度也为1，且相同或是p为'.'则返回true，反之返回false
- 若p的第二个字符不为*，若此时s为空返回false，否则判断首字符是否匹配，且从各自的第二个字符开始调用递归函数匹配
- 若p的第二个字符为*，若s不为空且字符匹配，调用递归函数匹配s和去掉前两个字符的p，若匹配返回true，否则s去掉首字母
- 返回调用递归函数匹配s和去掉前两个字符的p的结果
@reference:
http://www.cnblogs.com/grandyang/p/4461713.html
*/
class Solution1 {
public:
    bool isMatch(string s, string p) {
        if (p.empty()) return s.empty();
        if (p.size() == 1) {
            return (s.size() == 1 && (s[0] == p[0] || p[0] == '.'));
        }
        if (p[1] != '*') {
            if (s.empty()) return false;
            return (s[0] == p[0] || p[0] == '.') && isMatch(s.substr(1), p.substr(1));
        }
        while (!s.empty() && (s[0] == p[0] || p[0] == '.')) {
            if (isMatch(s, p.substr(2))) return true;
            s = s.substr(1);
        }
        return isMatch(s, p.substr(2));
    }
};

/*递归解法二
- 先判断p是否为空，若为空则根据s的为空的情况返回结果。
- 当p的第二个字符为*号时，由于*号前面的字符的个数可以任意，可以为0，
	- 那么先用递归来调用为0的情况，就是直接把这两个字符去掉再比较
	- 或者当s不为空，且第一个字符和p的第一个字符相同时，再对去掉首字符的s和p调用递归，注意p不能去掉首字符，
		因为*号前面的字符可以有无限个；
- 如果第二个字符不为*号，那么就比较第一个字符，然后对后面的字符串调用递归
*/
class Solution2 {
public:
    bool isMatch(string s, string p) {
        if (p.empty()) 
            return s.empty();
        if (p.size() > 1 && p[1] == '*') 
        {
            return isMatch(s, p.substr(2)) || (!s.empty() && (s[0] == p[0] || p[0] == '.') && isMatch(s.substr(1), p));
        } 
        else 
        {
            return !s.empty() && (s[0] == p[0] || p[0] == '.') && isMatch(s.substr(1), p.substr(1));
        }
    }
};

/*动态规划法

dp[i][j]表示s[0:i-1]是否能和p[0:j-1]匹配。

递推公式：由于只有p中会含有regular expression，所以以p[j-1]来进行分类。
p[j-1] != '.' && p[j-1] != '*'：dp[i][j] = dp[i-1][j-1] && (s[i-1] == p[j-1])
p[j-1] == '.'：dp[i][j] = dp[i-1][j-1]

而关键的难点在于 p[j-1] = '*'。由于星号可以匹配0，1，乃至多个p[j-2]。
1. 匹配0个元素，即消去p[j-2]，此时p[0: j-1] = p[0: j-3]
dp[i][j] = dp[i][j-2]

2. 匹配1个元素，此时p[0: j-1] = p[0: j-2]
dp[i][j] = dp[i][j-1]

3. 匹配多个元素，此时p[0: j-1] = { p[0: j-2], p[j-2], ... , p[j-2] }
dp[i][j] = dp[i-1][j] && (p[j-2]=='.' || s[i-2]==p[j-2])

@reference:
http://bangbingsyb.blogspot.com/2014/11/leetcode-regular-expression-matching.html
http://xiaohuiliucuriosity.blogspot.com/2014/12/regular-expression-matching.html
https://discuss.leetcode.com/topic/6183/my-concise-recursive-and-dp-solutions-with-full-explanation-in-c
*/
class Solution3 {
public:
    bool isMatch(string s, string p) {
        int m = s.size(), n = p.size();
        vector<vector<bool>> dp(m+1, vector<bool>(n+1,false));
        dp[0][0] = true;
        
        for(int i=0; i<=m; i++) 
        {
            for(int j=1; j<=n; j++) 
            {
                if(p[j-1]!='.' && p[j-1]!='*') 
                {
                    if(i>0 && s[i-1]==p[j-1] && dp[i-1][j-1])
                        dp[i][j] = true;
                }
                else if(p[j-1]=='.') 
                {
                    if(i>0 && dp[i-1][j-1])
                        dp[i][j] = true;
                }
                else if(j > 1) 
                {  //'*' cannot be the 1st element
                    if(dp[i][j-1] || dp[i][j-2])  // match 0 or 1 preceding element
                        dp[i][j] = true;
                    else if(i>0 && (p[j-2]==s[i-1] || p[j-2]=='.') && dp[i-1][j]) // match multiple preceding elements
                        dp[i][j] = true;
                }
            }
        }
        return dp[m][n];
    }
};