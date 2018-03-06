/*@Description: Best Time to Buy and Sell Stock II
Say you have an array for which the ith element is the price of a given stock on day i.
Design an algorithm to find the maximum profit. You may complete as many transactions as you like 
(ie, buy one and sell one share of the stock multiple times). However, you may not engage in multiple 
transactions at the same time (ie, you must sell the stock before you buy again).
*/

//累加相邻极小值点与极大值点之间的差值
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minVal = INT_MAX, maxPro = 0, sumPro = 0, size = prices.size();
        if(size == 0)   return 0;
        for(int i = 0; i < prices.size(); i++)
        {
            minVal = min(minVal, prices[i]);
            if(maxPro < prices[i] - minVal)
                maxPro = prices[i] - minVal;
            else
            {
                sumPro += maxPro;   //maxPro没有更新，说明前一个点为极值点，累加收益值，并更新最小值和单次最大收益
                minVal = prices[i];
                maxPro = 0;
            }
        }
        if(minVal != prices[size - 1])  //考虑最后一个点为极大值的情况
            sumPro += maxPro;
        return sumPro;
    }
};

//累加递增的股票差值
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        for(int i = 1; i < prices.size(); i++)
        {
            if(prices[i - 1] < prices[i])
                profit += prices[i] - prices[i - 1];
        }
        return profit;
    }
};