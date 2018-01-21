/*@Description: Merge Sorted Array
Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.
Note:
You may assume that nums1 has enough space (size that is greater or equal to m + n) to hold additional elements 
from nums2. The number of elements initialized in nums1 and nums2 are m and n respectively
*/

/**
nums1空间足够，可从后往前比较两个数组，并从nums1(m+n-1)尾部开始填充较大值，如果nums1数组遍历结束，只剩下nums2数组，则逐个复制
nums2剩下元素，如果nums2数组遍历结束，只剩下nums1数组，则不需要额外处理，因为合并后的元素都是存在nums1中
*/
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1, j = n - 1, k = m + n - 1;
        while(i >= 0 && j >= 0)
        {
            if(nums1[i] > nums2[j])
            {
                nums1[k] = nums1[i];
                i--;
            }
            else
            {
                nums1[k] = nums2[j];
                j--;
            }          
            k--;
        }
        while(j >= 0)
            nums1[k--] = nums2[j--];          
    }
};

/**
调用STL函数merge，注意合并后的元素不能直接填充到nums1中，需要另外定义一个数组存储空间
*/
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> result(m + n);
        std::merge(nums1.begin(), nums1.begin() + m, nums2.begin(), nums2.begin() + n, result.begin());
        nums1 = result;
    }
};