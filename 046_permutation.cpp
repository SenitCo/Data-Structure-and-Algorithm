/*@Description:  Permutations
Given a collection of distinct numbers, return all possible permutations.

For example,
[1,2,3] have the following permutations:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]
*/

/**+++++++++++++++++++++
回溯法(深度优先遍历DFS)，无重复元素，无需排序
++++++++++++++++++++++++*/
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        //sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        vector<int> permutation;
        backtrack(nums, result, permutation);
        return result;
    }
private:
    void backtrack(vector<int>& nums, vector<vector<int>>& result, vector<int>& permutation)
    {
        if(permutation.size() == nums.size())
        {
            result.push_back(permutation);
            return;
        }
        for(int i = 0; i < nums.size(); i++)
        {
            auto iter = find(permutation.begin(), permutation.end(), nums[i]);	
            if(iter == permutation.end())	//新元素不在已有序列中，则添加进来
            {
                permutation.push_back(nums[i]);
                backtrack(nums, result, permutation);
                permutation.pop_back();
            }
        }
    }
};


/**
ref: http://xiaohuiliucuriosity.blogspot.com/2014/12/permutations.html
*/
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int> > result;	    
	    permuteRecursive(nums, 0, result);
	    return result;
    }   
    // permute num[begin..end], invariant: num[0..begin-1] have been fixed/permuted
	void permuteRecursive(vector<int> &nums, int begin, vector<vector<int> > &result) {
		if (begin >= nums.size()) {
		    result.push_back(nums);	// one permutation instance
		    return;
		}
		
		for (int i = begin; i < nums.size(); i++) {
		    swap(nums[begin], nums[i]);
		    permuteRecursive(nums, begin + 1, result);
		    swap(nums[begin], nums[i]);		// reset
		}
    }
};

/**
对于nums = { 1, 2, 3 }，首先将第一个元素 1 插入序列中，然后插入第二个元素 2 ，2 可以在 1 的前面，
也可以在 1 的后面，因此得到结果{{1, 2}, {2, 1}}，同样地，第三个元素 3 插入到已有的排列中时，可以
在索引 0、1、2；依次类推，即可得到全排列。
*/
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        if(nums.size() == 0)
            return result;
        result.push_back({ nums[0] });
        for(int i = 1; i < nums.size(); i++)
        {
            vector<vector<int>> newRes;
            for(int j = 0; j <= i; j++)
            {
                for(auto perm : result)
                {
                    vector<int> newPerm = perm;
                    newPerm.insert(newPerm.begin() + j, nums[i]);
                    newRes.push_back(newPerm);
                }
            }
            result = newRes;
        }
        return result;
    }
};