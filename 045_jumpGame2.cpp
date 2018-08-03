/*@Description: Jump Game II
Given an array of non-negative integers, you are initially positioned at the first index of the array.
Each element in the array represents your maximum jump length at that position.
Your goal is to reach the last index in the minimum number of jumps.

For example:
Given array A = [2,3,1,1,4]
The minimum number of jumps to reach the last index is 2. (Jump 1 step from index 0 to 1, then 3 steps to the last index.)

Note:
You can assume that you can always reach the last index.
*/

/**
currentMax表示当前能够到达的最大长度，nextMax表示下一步可以到达的最大长度，在currentMax范围内遍历，
确定下一步的最长范围nextMax，超过currentMax则跳数递增，并让 currentMax = nextMax，继续下一轮遍历，
时间复杂度为O(N)
*/
class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size(); 
        if(n < 2)   return 0;
	    int level = 0, currentMax = 0, i = 0, nextMax = 0;
	    while(currentMax - i + 1 > 0){		//nodes count of current level>0
		    level++;
		    for(; i <= currentMax; i++){	//traverse current level , and update the max reach of next level
			    nextMax = max(nextMax, nums[i] + i);
			    if(nextMax >= n - 1)
                    return level;   // if last element is in level+1,  then the min jump=level 
		    }
		    currentMax = nextMax;
	    }
	    return 0;
    }
};


class Solution {
public:
    int jump(vector<int>& nums) {
        int cnt = 0, currentMax = 0, nextMax = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            if(i > currentMax)
            {
                currentMax = nextMax;
                cnt++;
            }
            nextMax = max(nextMax, nums[i] + i);
        }
        return cnt;
    }
};