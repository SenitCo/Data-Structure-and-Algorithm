/*@Desciption: Median of Two Sorted Arrays
There are two sorted arrays nums1 and nums2 of size m and n respectively.
Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).
*/

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int length = nums1.size() + nums2.size();
        vector<int> nums;
        int i = 0, j = 0, k = 0;
        double median = 0.0;
        if(nums1.empty() && nums2.empty())
            return 0.0;
        else if(nums1.empty())
            nums = nums2;
        else if(nums2.empty())
            nums = nums1;
        else
        {
            while(i < nums1.size() && j < nums2.size())
            {
                if(nums1[i] > nums2[j])
                {
                    nums.push_back(nums2[j]);
                    j++;
                }
                else
                {
                    nums.push_back(nums1[i]);
                    i++;
                }
            }
            while(i < nums1.size())
                nums.push_back(nums1[i++]);
            while(j < nums2.size())
                nums.push_back(nums2[j++]);
        }
        if(length % 2 == 1)
            median = nums[length / 2];
        else
            median = (nums[length / 2 - 1] + nums[length / 2]) / 2.0;
        return median;
    }
};

/*利用STL函数merge()合并两个已排序的向量，也可将两个向量首尾拼接，然后调用sort()函数*/
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) 
{
    int length = nums1.size() + nums2.size();
    vector<int> nums(length);
    double median = 0.0;       
    merge(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), nums.begin());
    if(length % 2 == 1)
        median = nums[length / 2];
    else
        median = (nums[length / 2 - 1] + nums[length / 2]) / 2.0;
    return median;
}

/**
O(log(min(m, n)))解法 
https://leetcode.com/problems/median-of-two-sorted-arrays/discuss/2481/Share-my-O(log(min(mn))-solution-with-explanation
http://windliang.cc/2018/07/18/leetCode-4-Median-of-Two-Sorted-Arrays/
*/
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) 
{
    int m = nums1.size(), n = nums2.size();
    if(m > n)
        return findMedianSortedArrays(nums2, nums1);
    int iMin = 0, iMax = m;
    while(iMin <= iMax)
    {
        int i = (iMin + iMax) / 2;
        int j = (m + n + 1) / 2 - i;
        if(j != 0 && i != m && nums1[i] < nums2[j - 1])
            iMin = i + 1;
        else if(j != n && i != 0 && nums1[i - 1] > nums2[j])
            iMax = i - 1;
        else
        {
            int maxLeft = 0;
            if(i == 0)  maxLeft = nums2[j - 1];
            else if(j == 0) maxLeft = nums1[i - 1];
            else    maxLeft = max(nums1[i - 1], nums2[j - 1]);
            if((m + n) % 2 == 1)    return maxLeft;
            
            int minRight = 0;
            if(i == m)  minRight = nums2[j];
            else if(j == n) minRight = nums1[i];
            else    minRight = min(nums1[i], nums2[j]);
            return (maxLeft + minRight) / 2.0;
        }
    }
    return 0.0;
}

//O(log(m + n))解法 
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        int left = (n + m + 1) / 2, right = (n + m + 2) / 2;
        return (getKth(nums1, 0, m - 1, nums2, 0, n - 1, left) + getKth(nums1, 0, m - 1, nums2, 0, n - 1, right)) * 0.5;
    }

    int getKth(vector<int>& nums1, int start1, int end1, vector<int>& nums2, int start2, int end2, int k)
    {
        int len1 = end1 - start1 + 1;
        int len2 = end2 - start2 + 1;
        if(len1 > len2)
            return getKth(nums2, start2, end2, nums1, start1, end1, k);
        if(len1 == 0)
            return nums2[start2 + k - 1];
        if(k == 1)
            return min(nums1[start1], nums2[start2]);

        int i = start1 + min(len1, k / 2) - 1;
        int j = start2 + min(len2, k / 2) - 1;
        if(nums1[i] > nums2[j])
            return getKth(nums1, start1, end1, nums2, j + 1, end2, k - (j - start2 + 1));
        else
            return getKth(nums1, i + 1, end1, nums2, start2, end2, k - (i - start1 + 1));
    }
};
