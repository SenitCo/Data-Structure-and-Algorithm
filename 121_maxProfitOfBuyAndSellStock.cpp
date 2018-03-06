/*@Description: Best Time to Buy and Sell Stock
Say you have an array for which the ith element is the price of a given stock on day i.
If you were only permitted to complete at most one transaction (ie, buy one and sell one 
share of the stock), design an algorithm to find the maximum profit.
Example 1: Input: [7, 1, 5, 3, 6, 4], Output: 5
max. difference = 6-1 = 5 (not 7-1 = 6, as selling price needs to be larger than buying price)
Example 2: Input: [7, 6, 4, 3, 1], Output: 0
In this case, no transaction is done, i.e. max profit = 0.
*/
/**
minVal表示已遍历元素中的最小值，profit表示当前收益的最大值
*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minVal = INT_MAX, profit = 0, size = prices.size();
        for(int i = 0; i < size; i++)
        {
            minVal = min(prices[i], minVal);
            profit = max(profit, prices[i] - minVal);
        }
        return profit;
    }
};

/**
转化为最大子数列问题（Kadane算法），从动态规划的角度考虑：
maxEndingHere[i] = max(0, maxEndingHere[i - 1] + prices[i] - prices[i - 1]),
maxEndingHere[i - 1]表示第i-1天售出股票的最大利润，maxEndingHere[i]表示第i天售出股票的最大利润，
因此需要加上前后两天的股票差价，maxSoFor表示到目前为止的最大利益（不一定在当天售出）
*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxEndingHere = 0, maxSoFar = 0, size = prices.size();
        for(int i = 1; i < size; i++)
        {
            maxEndingHere = max(0, maxEndingHere += prices[i] - prices[i - 1]);
            maxSoFar = max(maxEndingHere, maxSoFar);
        }
        return maxSoFar;
    }
};