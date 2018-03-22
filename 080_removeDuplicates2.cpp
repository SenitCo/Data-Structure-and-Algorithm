/*@Description: Remove Duplicates from Sorted Array II
Follow up for "Remove Duplicates":
What if duplicates are allowed at most twice?

For example,
Given sorted array nums = [1,1,1,2,2,3],
Your function should return length = 5, with the first five elements of nums being 1, 1, 2, 2 and 3. 
It doesn't matter what you leave beyond the new length.
*/

/**
sum变量统计所有有效元素的个数，count变量统计连续相同元素的个数，如果超过两个，则只在sum后面复制两个相同元素
*/
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int sum = 0, count = 0;
        for(int i = 0; i < nums.size();)
        {
            count = 1;
            while(i + count < nums.size() && nums[i + count] == nums[i])
                count++;
            i += count;
            count = count > 2 ? 2 : count;
            for(int j = sum; j < sum + count; j++)
                nums[j] = nums[i - count];	//i-count对应前面i+=count
            sum += count;        
        }
        return sum;
    }
};

/**
只保留k个相同元素的通用解法，注意数组是已经经过排序的
n表示fast指针，用于遍历每一个元素；i则是slow指针，表示有效元素的个数，
并在遍历过程中，逐个添加有效元素
*/
class Solution {
public:
    int removeDuplicates(vector<int>& nums, int k) {
        int i = 0;
        for (int n : nums)
            if (i < k || n > nums[i-k])
                nums[i++] = n;
        return i;
    }
};

/**
i表示fast指针，j表示slow指针
*/
class Solution {
public:
    int removeDuplicates(vector<int>& nums, int k) {
        if(nums.size() <= k)
            return nums.size();
        int cnt = 1, i = 1, j = 1;
        while (i < nums.size())
        {
            if(nums[i] != nums[i - 1])
            {
                cnt = 1;
                nums[j++] = nums[i];
            }
            else if(cnt < k)
            {
                nums[j++] = nums[i];
                cnt++;
            }
            i++;
        }
        return j;
    }
};