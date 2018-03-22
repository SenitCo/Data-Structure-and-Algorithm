/*@Description: Gray Code
The gray code is a binary numeral system where two successive values differ in only one bit.
Given a non-negative integer n representing the total number of bits in the code, print the 
sequence of gray code. A gray code sequence must begin with 0.
For example, given n = 2, return [0,1,3,2]. Its gray code sequence is:
00 - 0
01 - 1
11 - 3
10 - 2
Note:
For a given n, a gray code sequence is not uniquely defined.
For example, [0,2,3,1] is also a valid gray code sequence according to the above definition.
For now, the judge is able to judge based on one instance of gray code sequence. Sorry about that.
*/


/**
Adding one to a number results in flipping all the bits from the rightmost zero bit to the end, e.g. 
110011 + 1 = 110100. In the general form, i = ...?01...1, i+1 = ...?10...0, ? represents the left bit 
of the rightmost zero bit, the length of tailing one bits of i is the same as the length of tailing 
0 bits of i+1, and the bits from the beginning to the ? are the same.

Then i^(i>>1) = xxx(?^0)10...0, (i+1)^((i+1)>>1) = xxx(?^1)10...0. Since the bits from the beginning 
to the ? are the same, xxx part of both results must be same, it's obvious the tailing parts of 10...0 
must be same, and its length is the same as the length of tailing one bits of i, so there is only one 
bit difference comes from (?^0) and (?^1).

See https://discuss.leetcode.com/topic/8557/an-accepted-three-line-solution-in-java

简单翻译一下：对于i和i+1，i的二进制形式(i = ...?01...1)的最右边的连续为1和数量，和i+1的二进制形式(i+1 = ...?10...0)
的最右边连续为0的数量是一样的，？表示i的二进制形式的最右边的0比特和左边一个比特，同样的，i的起始比特位到？处与i+1的起始比特
位到？处是一致的。
考虑 i^(i>>1) = xxx(?^0)10...0，以及 (i+1)^((i+1)>>1) = xxx(?^1)10...0，由于起始比特位到？处是一致的，因此两个二进
制序列xxx部分是一致的，也就是说上述两个表达式只有 (?^0) 和 (?^1) 对应的比特位不一样
*/
class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> result;
        unsigned int num = 1 << n;
        for(unsigned int i = 0; i < num; i++)
        {
            result.push_back(i ^ (i >> 1));
        }
        return result;
    }
};

/**
Generate the sequence iteratively. For example, when n=3, we can get the result based on n=2.
00,01,11,10 -> (000,001,011,010 ) (110,111,101,100). The middle two numbers only differ at 
their highest bit, while the rest numbers of part two are exactly symmetric of part one. It 
is easy to see its correctness.
*/
class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> result;
        result.push_back(0);
        for(int i = 0; i < n; i++)
        {
            int size = result.size();
            for(int j = size - 1; j >= 0; j--)
            {
                result.push_back(result[j] | 1 << i);
            }
        }
        return result;
    }
};

