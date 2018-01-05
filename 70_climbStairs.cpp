/*@Description:  Climbing Stairs
You are climbing a stair case. It takes n steps to reach to the top.
Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
Note: Given n will be a positive integer.

Example 1:
Input: 2
Output:  2
Explanation:  There are two ways to climb to the top.
1. 1 step + 1 step
2. 2 steps

Example 2:
Input: 3
Output:  3
Explanation:  There are three ways to climb to the top.
1. 1 step + 1 step + 1 step
2. 1 step + 2 steps
3. 2 steps + 1 step
*/
/**
1. n = 1: steps = 1
2. n = 2: steps = 2
3. n > 2: steps[i] = steps[i - 1] + steps[i - 2]
对于第 i 个台阶，可以先走到 i - 1 个台阶，再走一步；或者先走到第 i - 2 个台阶，再走一个步（跨两个台阶），
而且两种走法没有重叠，因为最后一步不一样，所以存在以上迭代关系。本质上就是个 fibonacci 数列
*/

class Solution {
public:
    int climbStairs(int n) {
        vector<int> path(n);
        if(n == 1)
            return 1;
        if(n == 2)
            return 2;
        path[0] = 1;
        path[1] = 2;
        for(int i = 2; i < n; i++)
        {
            path[i] = path[i - 1] + path[i - 2];
        }
        return path[n - 1];
    }
};

/*******上述方法的简化版本，同样是迭代，而无需 n 个存储空间*******/
class Solution {
public:
    int climbStairs(int n) {
        int a = 1, b = 1;
        while (n--)
        {   
            b = b + a;
            a = b - a;
        }
        return a;
    }
};