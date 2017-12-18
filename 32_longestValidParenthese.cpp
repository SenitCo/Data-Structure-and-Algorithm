/*@Description:  Longest Valid Parentheses
Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) 
parentheses substring. For "(()", the longest valid parentheses substring is "()", which has length = 2.
Another example is ")()())", where the longest valid parentheses substring is "()()", which has length = 4.
*/

/**
遍历字符串中的元素，如果是'('，则将索引 i 压入栈中；如果是')'，则判断栈是否为空，若不为空切栈顶元素为'('，
pop栈顶元素，否则将索引压入栈中。然后计算栈中相邻元素(字符串索引)之间的距离，取最大值即为最大匹配长度。
*/
class Solution {
public:
    int longestValidParentheses(string s) {
        int len = s.length(), maxLen = 0;
        stack<int> st;
        for(int i = 0; i < len; i++)
        {
            if(s[i] == '(')
                st.push(i);
            else
            {
                if(!st.empty())  
                {
                    if(s[st.top()] == '(')
                        st.pop();
                    else
                        st.push(i);
                }
                else
                    st.push(i);
            }
        }
        if(st.empty())
            return len;
        
        int i = len, j = 0;
        while(!st.empty())
        {
            j = st.top();
            st.pop();
            maxLen = max(maxLen, i - j - 1);
            i = j;
        }
        maxLen = max(maxLen, i);
        return maxLen;
    }
};

/*简化版本，遍历字符串元素的同时，计算长度，并记录最大值*/
int longestValidParentheses(string s) 
{
    int len = s.length(), maxLen = 0;
    stack<int> st;
    st.push(-1);
    int topVal = 0;
    for(int i = 0; i < len; i++)
    {
        topVal = st.top();
        if(topVal != -1 && s[i] == ')' && s[topVal] == '(')
        {
            st.pop();
            maxLen = max(maxLen, i - st.top());
        }
        else
            st.push(i);
    }
    return maxLen;
}