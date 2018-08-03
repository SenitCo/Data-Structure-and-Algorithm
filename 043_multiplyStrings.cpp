/*@Description: Multiply Strings
Given two non-negative integers num1 and num2 represented as strings, return the product of num1 and num2.

Note:
The length of both num1 and num2 is < 110.
Both num1 and num2 contains only digits 0-9.
Both num1 and num2 does not contain any leading zero.
You must not use any built-in BigInteger library or convert the inputs to integer directly.
*/

/**
see https://github.com/SenitCo/Algorithm/blob/master/images/43_multiply.jpg
*/
class Solution {
public:
    string multiply(string num1, string num2) {
        int len1 = num1.length(), len2 = num2.length();
        vector<int> pos = vector<int>(len1 + len2, 0);
        int p1 = 0, p2 = 0, mul = 0, sum = 0;
        for(int i = len1 - 1; i >= 0; i--)
        {
            for(int j = len2 - 1; j >= 0; j--)
            {
                mul = (num1[i] - '0') * (num2[j] - '0');
                p1 = i + j;
                p2 = i + j + 1;
                sum = mul + pos[p2];    //+pos[p2]是因为经过j--,上一轮的进位由pos[p1]变为pos[p2]
                pos[p1] += sum / 10;    //pos[p1]表示这一轮的进位
                pos[p2] = sum % 10;
            }
        }
        int i = 0;
        string result;
        while(i < pos.size() && pos[i] == 0)    i++;
        for(; i < pos.size(); i++)
        {
            result.append(1, pos[i] + '0');
        }
        if(result.empty())
            return "0";
        return result;
    }
};