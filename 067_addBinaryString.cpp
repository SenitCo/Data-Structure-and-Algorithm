/*@Description: Add Binary
Given two binary strings, return their sum (also a binary string).
For example,
a = "11"
b = "1"
Return "100".
*/

class Solution {
public:
    string addBinary(string a, string b) {
        int step = 0, sum = 0;
        int i = a.length() - 1, j = b.length() - 1;
        string c;
        for(; i >= 0 && j >= 0; i--, j--)
        {
            sum = (a[i] - '0') + (b[j] - '0') + step;
            c.push_back(sum % 2 + '0');
            step = sum / 2;              
        }
        for(; i >= 0; i--)
        {
            sum = (a[i] - '0') + step;
            c.push_back(sum % 2 + '0');
            step = sum / 2;
        }
        for(; j >= 0; j--)
        {
            sum = (b[j] - '0') + step;
            c.push_back(sum % 2 + '0');
            step = sum / 2;
        }
        if(step > 0)
            c.push_back('1');
        reverse(c.begin(), c.end());
        return c;
            
    }
};

class Solution {
public:
    string addBinary(string a, string b) {
        string s;   
        int c = 0, i = a.size() - 1, j = b.size() - 1;
        while(i >= 0 || j >= 0 || c == 1)
        {
            c += i >= 0 ? a[i--] - '0' : 0;
            c += j >= 0 ? b[j--] - '0' : 0;
            s.push_back(c % 2 + '0');
            c /= 2;
        }
        reverse(s.begin(), s.end());
        return s;          
    }
};