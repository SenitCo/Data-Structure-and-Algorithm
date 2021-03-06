/*@Description: Unique Binary Search Trees
Given n, how many structurally unique BST's (binary search trees) that store values 1...n?
For example, Given n = 3, there are a total of 5 unique BST's.
   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
*/

/**DP方法
See https://leetcode.com/problems/unique-binary-search-trees/discuss/31666
令G(n)表示长度为n的序列的二叉搜索数的数量，F(i, n)表示在长度为 n 的序列中，以 i 为根结点的
二叉搜索数的数量，则有 G(n) = F(1, n) + F(2, n) + ... + F(n, n)，且 G(0) = G(1) = 1
对于F(i, n)，有 F(i, n) = G(i - 1) * G(n - i)
*/
class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n + 1, 0);
        dp[0] = dp[1] = 1;
        for(int i = 2; i < n + 1; i++)
        {
            for(int j = 1; j <= i; j++)
            {
                dp[i] += dp[j - 1] * dp[i - j];
            }
        }
        return dp[n];
    }
};