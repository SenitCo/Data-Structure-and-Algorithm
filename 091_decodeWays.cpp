/*@Description: Decode Ways
A message containing letters from A-Z is being encoded to numbers using the following mapping:
'A' -> 1
'B' -> 2
...
'Z' -> 26
Given an encoded message containing digits, determine the total number of ways to decode it.
For example, Given encoded message "12", it could be decoded as "AB" (1 2) or "L" (12).
The number of ways decoding "12" is 2.
*/

/**
r2：s[i-2]的解码方法数；r1：s[i-1]的解码方法数
如果s[i-1, i]组成的两位int数的取值范围在[1, 26]内，则s[i]的解码方法数等于s[i-1]与s[i-2]之和；
否则这两个字符无法组成一个有效的编码，s[i]的解码方法数与s[i-1]一样；如果某个字符为'0'，则前
一个字符只有为'1'或者'2'时，才是有效的编码串（此时s[i]与s[i-2]解码方法数一样），否则解码数为0
*/
class Solution {
public:
    int numDecodings(string s) {
        if(s.size() == 0 || s.front() == '0')
            return 0;
        int r2 = 1, r1 = 1;
        for(int i = 1; i < s.size(); i++)
        {
            if(s[i] == '0')
                r1 = 0;
            if(s[i - 1] == '1' || (s[i - 1] == '2' && s[i] < '7'))
            {
                r1 = r1 + r2;
                r2 = r1 - r2;
            }
            else
                r2 = r1;
        }
        return r1;
    }
};

/**
DP方法：从后往前遍历，出现为'0'的字符则跳过，考虑两个相邻的字符能否组成一个有效的编码，如果可以，则有
dp[i] = dp[i + 1] + dp[i + 2]；否则只能单个字符进行编码，dp[i] = dp[i + 1]
*/
class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        if(n == 0)  return 0;
        vector<int> dp(n + 1, 0);
        dp[n] = 1;
        dp[n - 1] = s[n - 1] == '0' ? 0 : 1;
        
        for(int i = n - 2; i >= 0; i--)
        {
            if(s[i] == '0')
                continue;
            else if(std::stoi(s.substr(i, 2)) <= 26)
                dp[i] = dp[i + 1] + dp[i + 2];
            else
                dp[i] = dp[i + 1];
        }
        return dp[0];
    }
};

/**
DP方法：从前往后遍历
*/
class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        if(n == 0)  return 0;
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        dp[1] = s[0] == '0' ? 0 : 1;
        
        for(int i = 2; i < n + 1; i++)
        {
            int pre1 = std::stoi(s.substr(i - 1, 1));
            int pre2 = std::stoi(s.substr(i - 2, 2));
            if(pre1 >= 1 && pre1 <= 9)
                dp[i] += dp[i - 1];
            if(pre2 >= 10 && pre2 <= 26)
                dp[i] += dp[i - 2];
        }
        return dp[n];
    }
};