/*@Description: Implement strStr().
Return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

Example 1:
Input: haystack = "hello", needle = "ll"
Output: 2
Example 2:
Input: haystack = "aaaaa", needle = "bba"
Output: -1
*/

/*****调用STL函数******/
class Solution {
public:
    int strStr(string haystack, string needle) {
        return haystack.find(needle);
    }
};

/*****朴素匹配算法*****/
class Solution {
public:
    int strStr(string haystack, string needle) {
        int len1 = haystack.length(), len2 = needle.length();
        for(int i = 0; i < len1 - len2 + 1; i++)
        {
            int j = 0;
            for(; j < len2; j++)
            {
                if(haystack[i + j] != needle[j])
                    break;
            }
            if(j == len2)
                return i;
        }
        return -1;
    }
};

/*****KMP算法*****/
class Solution {
public:
    int strStr(string haystack, string needle) {
        int len1 = haystack.length(), len2 = needle.length();
        if(len2 == 0)
            return 0;
        vector<int> next = getNext(needle);
        for(int i = 0, j = 0; i < len1;)
        {
            if(haystack[i] == needle[j])
            {
                i++;
                j++;
            }
            if(j == len2)
                return i - j;
            if(i < len1 && haystack[i] != needle[j])
            {
                if(j > 0)
                    j = next[j - 1];
                else
                    i++;
            }
        }
        return -1;
    }
private:
    vector<int> getNext(string& needle)
    {
        int len = needle.length();
        vector<int> next(len, 0);
        for(int i = 1, j = 0; i < len;)
        {
            if(needle[i] == needle[j])
                next[i++] = ++j;
            else if(j > 0)
                j = next[j - 1];
            else
                next[i++] = 0;
        }
        return next;
    }
};