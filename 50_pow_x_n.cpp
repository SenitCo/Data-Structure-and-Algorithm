/*Pow(x, n)
Implement pow(x, n).
Example 1:
Input: 2.00000, 10
Output: 1024.00000
Example 2:
Input: 2.10000, 3
Output: 9.26100
*/

class Solution {
public:
    double myPow(double x, int n) {
        return pow(x, n);
    }
};

class Solution {
public:
    double myPow(double x, int n) {
        long long ln = n;
        if(ln == 0) return 1;
        if(ln < 0)
        {
            ln = -ln;	//如果不定义成长整型对于 n = -2147483648 会越界
            x = 1 / x;
        }
        return ln % 2 == 0 ? myPow(x * x, ln / 2) : x * myPow(x * x, ln / 2);
    }
};

double myPow(double x, int n) 
{
    if(n < 0) return 1 / x * myPow(1 / x, -(n + 1));	//解决最小负整数反号越界的问题
    if(n == 0) return 1;
    if(n == 2) return x * x;
    if(n % 2 == 0) 
        return myPow(myPow(x, n / 2), 2);
    else
        return x * myPow(myPow(x, n / 2), 2);
}