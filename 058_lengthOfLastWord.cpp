/*@Description: Length of Last Word
Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of 
last word in the string. If the last word does not exist, return 0.
Note: A word is defined as a character sequence consists of non-space characters only.

Example:
Input: "Hello World"
Output: 5
*/

/**
从后往前遍历，找到第一个非空格的字符，记录位置为last，继续往前遍历，找到第一个空格字符，或者遍历完整个字符串，
即可求得最后一个有效word的长度
*/
class Solution {
public:
    int lengthOfLastWord(string s) {
        int len = s.length(), i = len - 1;
        for(; i >= 0 && s[i] == ' '; i--);
        int last = i;
        for(; i >= 0 && s[i] != ' '; i--);
        return last - i;     
    }
};


class Solution {
public:
    int lengthOfLastWord(string s) { 
        int len = 0, tail = s.length() - 1;
        while (tail >= 0 && s[tail] == ' ') tail--;
        while (tail >= 0 && s[tail] != ' ') {
            len++;
            tail--;
        }
        return len;
    }
};