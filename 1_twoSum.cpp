/*Description
Given an array of integers, return indices of the two numbers such that they add up to a specific target.
You may assume that each input would have exactly one solution, and you may not use the same element twice.
*/

class Solution1 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>::iterator outer, inter;
        vector<int> indices;
        int i = 0, j = 0;
        for(outer = nums.begin(); outer != nums.end(); outer++, i++)
        {
            for(inter = outer + 1, j = i + 1; inter != nums.end(); inter++, j++)
            {
                if(*outer + *inter == target)
                {
                    indices.push_back(i);
                    indices.push_back(j);
                    return indices;
                }
            }
        }
    }
};

class Solution2 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> indices;
        for(int i = 0; i < nums.size(); i++)
        {
            for(int j = i + 1; j < nums.size(); j++)
            {
                if(nums[i] + nums[j] == target)
                {
                    indices.push_back(i);
                    indices.push_back(j);
                    return indices;
                }
            }
        }
    }
};

/*****reference******/
vector<int> twoSum(vector<int> &numbers, int target)
{
    //Key is the number and value is its index in the vector.
    unordered_map<int, int> hash;
    vector<int> result;
    for (int i = 0; i < numbers.size(); i++) {
        int numberToFind = target - numbers[i];
        //if numberToFind is found in map, return them
        if (hash.find(numberToFind) != hash.end()) {
            //+1 because indices are NOT zero based
            result.push_back(hash[numberToFind] + 1);
            result.push_back(i + 1);            
            return result;
        }
        //number was not found. Put it in the map.
        hash[numbers[i]] = i;
    }
    return result;
}