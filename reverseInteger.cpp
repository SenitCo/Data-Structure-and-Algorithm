/*@Description: Reverse Integer
Given a 32-bit signed integer, reverse digits of an integer.
Assume we are dealing with an environment which could only hold integers within the 32-bit signed integer range. 
For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.
*/


/* 迭代除10取余，然后累乘(x10)累加，不用刻意注意正负数，符号在每一步的计算结果中有体现出来
末尾连续为0的情况也无需额外考虑
*/
class Solution {
public:
    int reverse(int x) {
        double result = 0;      //C++的int和long类型的范围一样！
        int bitValue = 0;
        while(x != 0)   
        {
            bitValue = x % 10;
            result = 10 * result + bitValue;
            x = x / 10;
        }
        //return (result < INT_MIN || result > INT_MAX) ? 0 : (int)result;
        if(result < INT_MIN || result > INT_MAX)
            return 0;
        return (int)result;
    }
};

/**无需额外判断是否溢出**/
int reverse(int x)
{
    int result = 0;
    while (x != 0)
    {
        int tail = x % 10;
        int newResult = result * 10 + tail;
        //if (newResult / 10 != result)
        if ((newResult - tail) / 10 != result)  //如溢出，则计算结果不相等
            return 0;
        result = newResult;
        x = x / 10;
    }
    return result;
}

/**将溢出判读条件放在循环内，可以提前终止**/
int reverse(int x) 
{
    double rev= 0;
    while( x != 0){
        rev= rev*10 + x % 10;
        x= x/10;
        if( rev >INT_MAX || rev < INT_MIN)  
            return 0;
    }
    return (int)rev;
}