/*@Description: Container With Most Water

Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water.

Note: You may not slant the container and n is at least 2.

*/

/*
Time Limit Exceeded，双重循环(O(n^2))，不可取
*/
class Solution {
public:
    int maxArea(vector<int>& height) {
        int size = height.size();
        int area = 0, maxArea = 0;
        for(int i = 0; i < size - 1; i++)
        {
            for(int j = i + 1; j < size; j++)
            {
                area = min(height[i], height[j]) * (j - i);
                if(area > maxArea)
                    maxArea = area;
            }
        }
        return maxArea;
    }
};

/*
从两边往中间遍历，如果左边高度height[left]小于右边height[right]，那么height[left]与中间剩余线段的组合面积只会减小(right--)，
因此选择left++，时间复杂度为O(n)
*/
class Solution {
public:
    int maxArea(vector<int>& height) {
        int size = height.size();
        int area = 0, maxArea = 0;
        int left = 0, right = size - 1;
        while(left < right)
        {
            if(height[left] > height[right])
            {   
                area = height[right] * (right - left);
                right--;               
            }
            else
            {
                area = height[left] * (right - left);
                left++;
            }   
            if(area > maxArea)
                maxArea = area;
        }
        return maxArea;
    }
};