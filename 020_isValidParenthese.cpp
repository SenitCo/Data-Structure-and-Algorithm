/*@ Description:  Valid Parentheses
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
*/

/*利用stack和hash表求解，将匹配的一对括号存入hashmap中，将左边括号依次压入栈中，
否则依次退栈，并和字符串中的元素做比较，是否匹配*/
bool isValid(string s) 
{
    if (s.length() % 2 == 1)
    return false;
    typedef pair<char, char> p2Char;
    unordered_map<char, char> parenthese{ p2Char('(', ')'), p2Char('{', '}'), p2Char('[', ']') };
    int len = s.length();
    stack<char> ss;
    for (int i = 0; i < len; i++)
    {
        if (parenthese.find(s[i]) != parenthese.end())
        {
            ss.push(s[i]);
            continue;
        }
        while (!ss.empty() && i < len)
        {
            char c = ss.top();
            if (parenthese[c] == s[i])
            {
                ss.pop();
                i++;
            }
            else if (parenthese.find(s[i]) == parenthese.end())
            {
                return false;
            }
            else
            {
                i--;
                break;
            }
        }
    }
    if (!ss.empty())
        return false;
    return true;
}

/*法一简化版*/
bool isValid(string s) 
{
    typedef pair<char, char> p2Char;
    unordered_map<char, char> parenthese{ p2Char('(', ')'), p2Char('{', '}'), p2Char('[', ']') };
    int len = s.length();
    stack<char> ss;
    for (int i = 0; i < len; i++)
    {
        if (parenthese.find(s[i]) != parenthese.end())
        {
            ss.push(s[i]);
        }
        else 
        {
            if(ss.empty() || parenthese[ss.top()] != s[i])
                return false;
            else
                ss.pop();
        }
    }
    return ss.empty();
}

/*压入栈中的为右边括号*/
bool isValid(string s) 
{
    stack<char> ss;
    for(int i = 0; i < s.length(); i++)
    {
        switch(s[i])
        {
            case '(': ss.push(')'); break;
            case '{': ss.push('}'); break;
            case '[': ss.push(']'); break;
            default:
                if(ss.empty() || ss.top() != s[i])
                    return false;
                else
                    ss.pop();
        }
    }
    return ss.empty();
}