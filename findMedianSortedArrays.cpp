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
            for(i = 0, j = 0; i < nums1.size(); i++)
            {
                for(; j < nums2.size(); j++)
                {
                    if(nums1[i] > nums2[j])
                        nums.push_back(nums2[j]);
                    else
                       break;             
                }
                nums.push_back(nums1[i]);
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