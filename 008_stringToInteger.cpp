/*@Description: String to Integer (atoi)
Implement atoi to convert a string to an integer.
*/

/*处理四种情况：开头连续的空格；正负符号；不合理的输入；溢出
不合理的输入"+-123"、"- 123"、"b123"等均输出0，"123a"这种情况输出前面的合理数字123
*/
class Solution {
public:
    int myAtoi(string str) {
        double result = 0;
        int i = 0, flag = 0;

        while(str[i] == ' ')
            i++;
        if(str[i] == '-')
        {
            flag = 1;
            i++;
        }
        else if(str[i] == '+')
        {
            i++;
        }
       
        for(; i < str.size(); i++)
        {
            if(str[i] > '9' || str[i] < '0')
                break;
            result = result * 10 + str[i]   - '0';
        }
        if(flag)
            result = -result;
        if(result > INT_MAX)
            result = INT_MAX;
        if(result < INT_MIN)
            result = INT_MIN;
        return (int)result;
    }
};

int myAtoi(string str) 
{
    int sign = 1, base = 0, i = 0;
    while (str[i] == ' ') { i++; }
    if (str[i] == '-' || str[i] == '+') 
    {
        sign = 1 - 2 * (str[i++] == '-'); 
    }
    while (str[i] >= '0' && str[i] <= '9')
    {
        if (base >  INT_MAX / 10 || (base == INT_MAX / 10 && str[i] - '0' > 7)) 
        {
            if (sign == 1) 
                return INT_MAX;
            else 
                return INT_MIN;
        }
        base  = 10 * base + (str[i++] - '0');
    }
    return base * sign;
}