/*@Description: Trapping Rain Water. See https://github.com/SenitCo/Algorithm/blob/master/images/42_rainwatertrap.png
Given n non-negative integers representing an elevation map where the width of each bar is 1, 
compute how much water it is able to trap after raining.

For example, 
Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.

The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units 
of rain water (blue section) are being trapped. Thanks Marcos for contributing this image!
*/

/**
从左至右遍历，搜索可以储水的最大区域，并计算总和
*/

class Solution {
public:
    int trap(vector<int>& height) {
        int width = height.size();
        int left = 0, right = 0, cnt = 0, sum = 0;
        for(int i = 0; i < width;)
        {
            if(i < width - 1 && height[i] > height[i + 1])	//确定高度有下降趋势，记为左边界left
            {
                cnt = 0;
                left = i;
                right = left + 1;
                i += 1;
                //搜索第一个不低于左边界的位置，若不存在，则将向右搜索过程中的最高位置记为右边界
                while(i < width  && height[i] < height[left])	
                {	
                    if(height[i] >= height[right])				
                    {
                        right = i;
                    }
                    cnt += height[left] - height[i];			//累积区域和（假设左边界较低）
                    i++;
                }
                if(i >= width)	//若左边界高于右边界，则重新计算区域和；然后从右边界开始继续搜索下一个储水区域				
                {
                    for(i = left + 1, cnt = 0; i < right; i++)
                    {
                        cnt += height[right] - height[i];
                    }
                }
                sum += cnt;
            }
            else
                i++;
            
        }
        return sum;
    }
};

/**
Instead of calculating area by height*width, we can think it in a cumulative way. In other words, 
sum water amount of each bin(width=1). Search from left to right and maintain a max height of left 
and right separately, which is like a one-side wall of partial container. Fix the higher one and 
flow water from the lower part. For example, if current height of left is lower, we fill water in 
the left bin. Until left meets right, we filled the whole container.
从两边向中间遍历，累积计算储水量总和
*/
class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int maxLeft = 0, maxRight = 0, sum = 0;
        while(left <= right)
        {
            if(height[left] < height[right])
            {
                if(height[left] >= maxLeft)
                    maxLeft = height[left];
                else
                    sum += maxLeft - height[left];
                left++;
            }
            else
            {
                if(height[right] >= maxRight)
                    maxRight = height[right];
                else
                    sum += maxRight - height[right];
                right--;
            }
        }
        return sum;
    }
};


class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0, r = height.size()-1, level = 0, water = 0;
        while (l < r) 
        {
            int lower = height[height[l] < height[r] ? l++ : r--];
            level = max(level, lower);
            water += level - lower;
        }
         return water;
    }
};