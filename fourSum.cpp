/*@Description: 4Sum

Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.

Note: The solution set must not contain duplicate quadruplets.

For example, given array S = [1, 0, -1, 0, -2, 2], and target = 0.

A solution set is:
[
  [-1,  0, 0, 1],
  [-2, -1, 1, 2],
  [-2,  0, 0, 2]
]

*/

/*hash表解法：将元素两两之和作为主键值key，元素索引(i, j)组成的vetor<pair>作为map value存入hash表中，时间复杂度为(O(N^2))*/
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result1;
        set<vector<int>> result2;
        typedef pair<int, int> p2Int;
        unordered_map<int, vector<p2Int>> nmap;
        int size = nums.size();
        if(size < 4)
            return result1;
        sort(nums.begin(), nums.end());
        
        for(int i = 0; i < size - 1; i++)
        {
            for(int j = i + 1; j < size; j++)
            {
                nmap[nums[i] + nums[j]].push_back(make_pair(i, j));
            }
        }
        int value = 0;
        for(int i = 0; i < size - 3; i++)
        {
            if(nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3] > target)
                break;
            for(int j = i + 1; j < size - 2; j++)
            {
                value = target - (nums[i] + nums[j]);
                if(nmap.find(value) != nmap.end())
                {
                    for(auto&& p : nmap[value])
                    {
                        if(p.first > j)
                        {
                            vector<int> tmp = { nums[i], nums[j], nums[p.first], nums[p.second] };
                            result2.insert(tmp);
                        }
                    }
                }                   
            }
        }
        for(auto&& x : result2)
            result1.push_back(x);
        return result1;
    }
};

/*转化为3Sum问题，(1)处的处理保证vector中的元素是有序的，时间复杂度为O(N^3)*/
vector<vector<int>> fourSum(vector<int>& nums, int target) 
{
    vector<vector<int>> result;
    int size = nums.size();
    if(size < 4)
        return result;
    sort(nums.begin(), nums.end());
    for(int i = 0; i < size -3; i++)
    {
        if(i > 0 && nums[i] == nums[i - 1]) continue;       //(1)
        if(nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3] > target)  break;
        if(nums[i] + nums[size - 1] + nums[size - 2] + nums[size - 3] < target) continue;
        
        for(int j = i + 1; j < size - 2; j++)
        {
            if(j > i + 1 && nums[j] == nums[j - 1]) continue;      //(1)
            if(nums[i] + nums[j] + nums[j + 1] + nums[j + 2] > target)  break;
            if(nums[i] + nums[j] + nums[size - 1] + nums[size - 2] < target)    continue;
            
            for(int left = j + 1, right = size - 1; left < right;)
            {              
                int value = nums[i] + nums[j] + nums[left] + nums[right];
                if(value == target)
                {
                    result.push_back({nums[i], nums[j], nums[left], nums[right]});
                    left++;
                    right--;
                }
                else if(value < target)
                    left++;
                else
                    right--;                   
            }
        }
    }
    vector<vector<int>>::iterator iter = unique(result.begin(), result.end());
    result.erase(iter, result.end());
    return result;
}

/*转化为3Sum问题，(1)处保证vector中的元素是有序的，(2)处保证元素是非重复的*/
vector<vector<int>> fourSum(vector<int>& nums, int target) 
{
    vector<vector<int>> result;
    int size = nums.size();
    if(size < 4)
        return result;
    sort(nums.begin(), nums.end());
    for(int i = 0; i < size -3; i++)
    {
        if(i > 0 && nums[i] == nums[i - 1]) continue;
        if(nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3] > target)  break;
        if(nums[i] + nums[size - 1] + nums[size - 2] + nums[size - 3] < target) continue;
        
        for(int j = i + 1; j < size - 2; j++)
        {
            if(j > i + 1 && nums[j] == nums[j - 1]) continue;
            if(nums[i] + nums[j] + nums[j + 1] + nums[j + 2] > target)  break;
            if(nums[i] + nums[j] + nums[size - 1] + nums[size - 2] < target)    continue;
            
            for(int left = j + 1, right = size - 1; left < right;)
            {              
                int value = nums[i] + nums[j] + nums[left] + nums[right];
                if(value == target)
                {
                    result.push_back({nums[i], nums[j], nums[left], nums[right]});
                    do { left++; } while(nums[left] == nums[left - 1] && left < right); //(2)跳过重复元素
                    do { right--; } while(nums[right] == nums[right + 1] && left < right);
                }
                else if(value < target)
                    left++;
                else
                    right--;                   
            }
        }
    }
    return result;
}