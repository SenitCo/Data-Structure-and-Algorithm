/*@Description: Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle 
containing only 1's and return its area.
For example, given the following matrix:
1 0 1 0 0
1 0 1 1 1
1 1 1 1 1
1 0 0 1 0
Return 6.
*/

/**
See https://leetcode.com/problems/maximal-rectangle/discuss/29054
*/
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.empty())  return 0;
        const int m = matrix.size();
        const int n = matrix[0].size();
        vector<int> left(n, 0), right(n, n), height(n, 0);
        int maxArea = 0;
        for(int i = 0; i < m; i++)
        {
            int curLeft = 0, curRight = n;
            for(int j = 0; j < n; j++)
            {
                if(matrix[i][j] == '1')
                    height[j]++;
                else
                    height[j] = 0;
            }
            
            for(int j = 0; j < n; j++)
            {
                if(matrix[i][j] == '1')
                    left[j] = max(left[j], curLeft);
                else
                {
                    left[j] = 0;
                    curLeft = j + 1;
                }
            }
            
            for(int j = n - 1; j >= 0; j--)
            {
                if(matrix[i][j] == '1')
                    right[j] = min(right[j], curRight);
                else
                {
                    right[j] = n;
                    curRight = j;
                }
            }
            
            for(int j = 0; j < n; j++)
            {
                maxArea = max(maxArea, (right[j] - left[j]) * height[j]);
            }
            
        }
        return maxArea;
    }
};

/**
采用Largest Rectangle in Histogram中的方法：逐行遍历，计算每一行中元素的高度（纵向连续为'1'的个数），
然后将其视为一个计算直方图中最大矩形面积的问题求解
See https://leetcode.com/problems/maximal-rectangle/discuss/29064
*/
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.empty())  return 0;
        const int m = matrix.size();
        const int n = matrix[0].size();
        vector<int> height(n + 1, 0);
        int rectWidth = 0, rectHeight = 0, maxArea = 0;
        
        for(int i = 0; i < m; i++)
        {
            stack<int> index;
            for(int j = 0; j < n + 1; j++)
            {
                if(j < n)
                {
                    if(matrix[i][j] == '1')
                        height[j]++;
                    else
                        height[j] = 0;
                }
                
                while(!index.empty() && height[index.top()] >= height[j])   
                {
                    rectHeight = height[index.top()];
                    index.pop();
                    rectWidth = index.empty() ? j : j - index.top() - 1;
                    if(rectWidth * rectHeight > maxArea)
                        maxArea = rectWidth * rectHeight;
                }
                index.push(j);
            }
        }
        
        return maxArea;
    }
};