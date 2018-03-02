/*@Description: Longest Consecutive Sequence
Given an unsorted array of integers, find the length of the longest consecutive elements sequence.
For example, Given [100, 4, 200, 1, 3, 2], The longest consecutive elements sequence is [1, 2, 3, 4]. 
Return its length: 4.
Your algorithm should run in O(n) complexity.
*/

/**
使用一个hash表存储每个元素所在序列的最大长度，依次遍历数组元素val，并判断元素相邻值(val-1, val+1)
是否在hash表中，如果存在则取出其对应的长度，并进行合并
*/
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> mp;
        int result = 0, left = 0, right = 0, length = 0;
        for(int num : nums)
        {
            if(mp.find(num) == mp.end())
            {
                if(mp.find(num - 1) != mp.end())
                    left = mp[num - 1];
                else left = 0;
                
                if(mp.find(num + 1) != mp.end())
                    right = mp[num + 1];
                else right = 0;

                int length = left + right + 1;
                mp[num] = length;
                mp[num - left] = length;    //同时更新序列边界元素的长度值
                mp[num + right] = length;
                result = max(result, length);
            }
        }
        return result;
    }
};

