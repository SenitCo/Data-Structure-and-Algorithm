/*@Description: Best Time to Buy and Sell Stock III
Say you have an array for which the ith element is the price of a given stock on day i.
Design an algorithm to find the maximum profit. You may complete at most two transactions.
Note: You may not engage in multiple transactions at the same time (ie, you must sell the 
stock before you buy again).
*/

/**DP算法：可扩展到最多交易k次
定义local[i][j]为在到达第i天时最多可进行j次交易并且最后一次交易在最后一天卖出的最大利润，此为局部最优。
定义global[i][j]为在到达第i天时最多可进行j次交易的最大利润，此为全局最优。递推式为：
diff = prices[i] - prices[i - 1]
local[i][j] = max(global[i - 1][j - 1] + max(diff, 0), local[i - 1][j] + diff)
global[i][j] = max(local[i][j], global[i - 1][j])
其中局部最优值是比较前一天并少交易一次的全局最优加上大于0的差值，和前一天的局部最优加上差值中取较大值，
而全局最优比较局部最优和前一天的全局最优。
*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty())  return 0;
        int n = prices.size();
        vector<vector<int>> local(n, vector<int>(3, 0)), global(n, vector<int>(3, 0));
        for(int i = 1; i < n; i++)
        {
            int diff = prices[i] - prices[i - 1];
            for(int j = 1; j < 3; j++)
            {
                local[i][j] = max(global[i - 1][j - 1] + max(diff, 0), local[i - 1][j] + diff); 
                global[i][j] = max(global[i - 1][j], local[i][j]);
            }
        }
        return global[n - 1][2];
    }
};

/**
用一维数组来代替二维数组，可以极大地减少空间，由于覆盖的顺序关系，遍历j需要从2到1，这样可以取到正确的g[j-1]值，
而非已经被覆盖过的值
*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty())  return 0;
        int n = prices.size();
        int local[3] = { 0 }, global[3] = { 0 };
        for(int i = 1; i < n; i++)
        {
            int diff = prices[i] - prices[i - 1];
            for(int j = 2; j >= 1; j--)
            {
                local[j] = max(global[j - 1] + max(0, diff), local[j] + diff);
                global[j] = max(global[j], local[j]);
            }
        }
        return global[2];
    }
};

/**
lowestBuyPrice1始终为输入数组中的最低价，maxProfit1记录到目前为止最高价与最低价的差价（最高价需在最低价后面），
lowestBuyPrice2为相对最小值，maxProfit2则为最多买卖两次的累积最大收益
*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit1 = 0, maxProfit2 = 0, lowestBuyPrice1 = INT_MAX, lowestBuyPrice2 = INT_MAX;
        for(int p : prices)
        {
            maxProfit2 = max(maxProfit2, p - lowestBuyPrice2);
            lowestBuyPrice2 = min(lowestBuyPrice2, p - maxProfit1);
            maxProfit1 = max(maxProfit1, p - lowestBuyPrice1);
            lowestBuyPrice1 = min(lowestBuyPrice1, p);
        }
        return maxProfit2;
    }
};