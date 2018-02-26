/*@Description: Single Number II
Given an array of integers, every element appears three times except for one, which appears exactly once. 
Find that single one.
Note: Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
*/

//hash表，用到了额外的存储空间
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> cnt;
        for(int i = 0; i < nums.size(); i++)
        {
            cnt[nums[i]]++;
        }
        for(auto t : cnt)
        {
            if(t.second == 1)
                return t.first;
        }
        return 0;
    }
};

//位操作，对int型数据（32位）分别进行求和除以3取余，所得数字即为所求
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        vector<int> digit(32, 0);   //固定数组仍为常量存储空间
        int result = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            for(int j = 0; j < 32; j++)
            {
                digit[j] += (nums[i] >> j) & 1;
            }
        }
        for(int i = 0; i < 32; i++)
        {
            result += (digit[i] % 3) << i;
        }
        return result;
    }
};

/**
位操作：用两个int数据分别存储数组和的低位和高位，最大次数为3，因此使用两位即可表示，
所以采用两个int型数据，在累加过程中需要对3取余，因此每一位的变化过程为00(0)->01(1)
->10(2)->00(3/0)。代码中的表达式可由数字逻辑的真值表求得
See http://blog.csdn.net/yutianzuijin/article/details/50597413
*/
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int low = 0, high = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            low = (low ^ nums[i]) & ~high;
            high = (high ^ nums[i]) & ~low;
        }
        return low;
    }
};