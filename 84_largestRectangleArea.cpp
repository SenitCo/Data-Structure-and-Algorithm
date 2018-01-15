/*@Description:  Largest Rectangle in Histogram
Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, 
find the area of largest rectangle in the histogram. Above is a histogram where width of each bar is 1, 
given height = [2,1,5,6,2,3].

The largest rectangle is shown in the shaded area, which has area = 10 unit.
For example,
Given heights = [2,1,5,6,2,3],
return 10.
image: https://github.com/SenitCo/Algorithm/blob/master/images/84_histogram_area.png
*/

/**
定义一个存储索引的数组(stack)——index，如果原数组中高度依次递增，则将对应索引push到index中，否则从栈顶
依次取出元素计算面积
*/
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int area = 0, maxArea = 0;
        vector<int> index;
        heights.push_back(0);
        for(int i = 0; i < heights.size(); i++)
        {	//index中元素对应高度必定是递增的
            while(index.size() > 0 && heights[index.back()] >= heights[i])
            {
                int h = heights[index.back()];	//h必定是当前取出的高度最小值
                index.pop_back();
                //begin表示计算面积区间的前一个索引，i是区间的后一个索引，整个区间范围为(i-begin-1)
                int begin = index.size() > 0 ? index.back() : -1;	
                area = (i - begin - 1) * h;
                if(area > maxArea)
                    maxArea = area;
            }
            index.push_back(i);
        }
        return maxArea;
    }
};