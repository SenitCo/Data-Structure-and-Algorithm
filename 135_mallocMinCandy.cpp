/*@Description: Candy
There are N children standing in a line. Each child is assigned a rating value.
You are giving candies to these children subjected to the following requirements:
Each child must have at least one candy.
Children with a higher rating get more candies than their neighbors.
What is the minimum candies you must give?
*/

//DP方法：分别前向、后向遍历一次，更新每个人应该分配的最小数量
class Solution {
public:
    int candy(vector<int>& ratings) {
        int size = ratings.size();
        if(size < 2)
            return size;
        int result = 0;
        vector<int> nums(size, 1);
        for(int i = 1; i < size; i++)
        {
            if(ratings[i] > ratings[i - 1])
                nums[i] = nums[i - 1] + 1;
        }
        for(int i = size - 1; i > 0; i--)
        {
            if(ratings[i - 1] > ratings[i])
                nums[i - 1] = max(nums[i - 1], nums[i] + 1);
            result += nums[i];  //在第二次遍历(反向)时直接累加，避免再循环一次
        }
        result += nums[0];
        return result;
    }
};