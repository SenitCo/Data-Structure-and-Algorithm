/*@Description: Minimum Window Substring
Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n).

For example,
S = "ADOBECODEBANC"
T = "ABC"
Minimum window is "BANC".

Note:
If there is no such window in S that covers all characters in T, return the empty string "".
If there are multiple such windows, you are guaranteed that there will always be only one unique minimum window in S.
*/

/**
1.用两个“指针”begin、end指向s中字符代表一个窗口
2.移动end指针搜索有效窗口(窗口中包含t中所有字符)
3.移动begin指针缩小有效窗口范围
为了让[begin, end)窗口成为一个有效窗口，需要一个映射表map(char, count)，存储t中每个字符出现的次数（t中字符可重复），
并定义一个counter统计t中的字符数，如果s中出现t中字符，即map[s[end]]>0，则counter--，直至counter为0，说明已获取一个
有效窗口，因此移动begin指针缩小窗口范围。一个比较关键的步骤就是end指针每次步进前，都会执行map[s[end]]--操作，这样
如果t中已不存在对应字符，就会使得该字符的统计数为负。在得到一个有效的窗口（counter=0）时，判断现有窗口和之前窗口的
大小，取窗口较小值，并记录起始位置head=begin，如果遇到map[s[begin]] == 0，说明遇到了t中一个字符且该字符为有效窗口的
左边界，begin指针再往前走，窗口中就不包含t中所有字符，因此counter计数值自增。和end指针一样，begin指针每次步进前都要
执行map[s[begin]]++操作，对于s="bba",t="ba"，t中字符'b'只出现一次，而s中出现两次，end指针的map[s[end]]--操作使得
map['b']<0，因此begin指针在步进时需要逐步恢复每个字符的统计值。
*/
class Solution {
public:
    string minWindow(string s, string t) {
        //vector<int> map(128, 0);
        unordered_map<char, int> map;
        for(int i = 0; i < t.size(); i++)
            map[t[i]]++;
        int head = 0, begin = 0, end = 0, len = INT_MAX, count = t.size();
        while(end < s.size())
        {
            if(map[s[end]] > 0)
                count--;
            map[s[end]]--;
            end++;
            while(count == 0)
            {
                if(end - begin < len)
                {
                    head = begin;
                    len = end - begin;
                }
                if(map[s[begin]] == 0)
                    count++;
                map[s[begin]]++;
                begin++;
            }
        }
        return len == INT_MAX ? "" : s.substr(head, len);
    }
};

// See https://leetcode.com/problems/minimum-window-substring/discuss/26808

/**
可读性较差的简化版本
*/
string minWindow(string s, string t) 
{
    vector<int> map(128,0);
    for(auto c: t) map[c]++;
    int counter=t.size(), begin=0, end=0, d=INT_MAX, head=0;
    while(end<s.size()){
        if(map[s[end++]]-->0) counter--; //in t
        while(counter==0){ //valid
            if(end-begin<d)  d=end-(head=begin);
            if(map[s[begin++]]++==0) counter++;  //make it invalid
        }  
    }
    return d==INT_MAX? "":s.substr(head, d);
}


/***************子串搜索的模板*******************/

/**
For most substring problem, we are given a string and need to find a substring of it which satisfy some restrictions. 
A general way is to use a hashmap assisted with two pointers. The template is given below.
**/
int findSubstring(string s)
{
    vector<int> map(128,0);
    int counter; // check whether the substring is valid
    int begin=0, end=0; //two pointers, one point to tail and one  head
    int d; //the length of substring

    for() { /* initialize the hash map here */ }

    while(end<s.size()){

        if(map[s[end++]]-- ?){  /* modify counter here */ }

        while(/* counter condition */){ 
             
             /* update d here if finding minimum*/

            //increase begin to make it invalid/valid again
            
            if(map[s[begin++]]++ ?){ /*modify counter here*/ }
        }  

        /* update d here if finding maximum*/
    }
    return d;
}

/**
One thing needs to be mentioned is that when asked to find maximum substring, we should update maximum after the inner 
while loop to guarantee that the substring is valid. On the other hand, when asked to find minimum substring, we should 
update minimum inside the inner while loop.
*/

/**
The code of solving Longest Substring with At Most Two Distinct Characters is below:
*/
int lengthOfLongestSubstringTwoDistinct(string s) 
{
    vector<int> map(128, 0);
    int counter=0, begin=0, end=0, d=0; 
    while(end<s.size()){
        if(map[s[end++]]++==0) counter++;
        while(counter>2) if(map[s[begin++]]--==1) counter--;
        d=max(d, end-begin);
    }
    return d;
}

/**
The code of solving Longest Substring Without Repeating Characters is below:
*/

int lengthOfLongestSubstring(string s) 
{
    vector<int> map(128,0);
    int counter=0, begin=0, end=0, d=0; 
    while(end<s.size()){
        if(map[s[end++]]++>0) counter++; 
        while(counter>0) if(map[s[begin++]]-->1) counter--;
        d=max(d, end-begin); //while valid, update d
    }
    return d;
}