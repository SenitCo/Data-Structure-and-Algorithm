/*@Description: Count and Say
The count-and-say sequence is the sequence of integers with the first five terms as following:

1.     1
2.     11
3.     21
4.     1211
5.     111221
1 is read off as "one 1" or 11.
11 is read off as "two 1s" or 21.
21 is read off as "one 2, then one 1" or 1211.
Given an integer n, generate the nth term of the count-and-say sequence.

Note: Each term of the sequence of integers will be represented as a string.

Example 1:
Input: 1
Output: "1"
Example 2:
Input: 4
Output: "1211"
*/

/**
第i+1个字符串是第i个字符串的读法，第一字符串为 “1”
比如第四个字符串是1211，它的读法是 1个1、1个2,2个1，因此第五个字符串是111221。
第五个字符串的读法是：3个1、2个2、1个1，因此第六个字符串是312211 
*/
class Solution {
public:
    string countAndSay(int n) {
        if(n < 1)   return "";
        string result = "1";
        for(int i = 1; i < n; i++)
        {
            string temp;
            int count = 1;
            char prev = result[0];
            result.push_back('#');		//处理边界条件，避免退出下面的循环后再进行一次+=和push处理
            for(int j = 1; j < result.size(); j++)
            {
                if(prev == result[j])
                    count++;
                else
                {
                    temp += to_string(count);
                    temp.push_back(prev);
                    prev = result[j];
                    count = 1;
                }
            }
            result = temp;
        }
        return result;
    }
};

string countAndSay(int n) 
{
    if (n == 0) return "";
    string res = "1";
    while (--n) {
        string cur = "";
        for (int i = 0; i < res.size(); i++) {
            int count = 1;
             while ((i + 1 < res.size()) && (res[i] == res[i + 1])){
                count++;    
                i++;
            }
            cur += to_string(count) + res[i];
        }
        res = cur;
    }
    return res;
}