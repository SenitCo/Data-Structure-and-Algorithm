/*@Description: Remove Duplicates from Sorted Array
Given a sorted array, remove the duplicates in-place such that each element appear only once and return the new length.
Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.

Example:
Given nums = [1,1,2],
Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively.
It doesn't matter what you leave beyond the new length.
*/

/*直接使用STL的unique函数，不过向量的size不会改变，需重新计数*/
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        auto iters = unique(nums.begin(), nums.end());
        int cnt = 0;
        for(auto it = nums.begin(); it != iters; it++, cnt++);
        return cnt;           
    }
};

/*遍历向量，并移除重复元素*/
int removeDuplicates(vector<int>& nums) 
{
    if (nums.size() < 2)
        return nums.size();
    int cnt = 0;
    for(auto iter = nums.begin(); iter != nums.end(); iter++)
    {
        while(iter != nums.end() - 1 && *iter == *(iter + 1)) 
        {
            iter = nums.erase(iter);
        }
        cnt++;
    }
    return cnt;
}

/*++++++++++++++++++++++++++++++++++++*/
int removeDuplicates(vector<int>& nums) 
{
    if (nums.size() < 2)
        return nums.size();
    int cnt = 1;
    for(int i = 1; i < nums.size(); i++)
    {
        if(nums[i] != nums[i - 1])
            nums[cnt++] = nums[i];
    }
    return cnt;
}

