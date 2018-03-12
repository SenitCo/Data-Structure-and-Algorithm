/*@Description: Path Sum II
Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.
For example: Given the below binary tree and sum = 22,
              5
             / \
            4   8
           /   / \
          11  13  4
         /  \    / \
        7    2  5   1
return
[
   [5,4,11,2],
   [5,8,4,5]
]
*/

//深度优先遍历 + 回溯法
class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> result;
        if(!root)   return result;
        vector<int> path;
        traverse(root, sum, result, path);
        return result;
    }
private:
    void traverse(TreeNode* node, int sum, vector<vector<int>>& result, vector<int>& path)
    {
        if(node == NULL)    return;
        path.push_back(node->val);
        if(!node->left && !node->right && sum == node->val)
            result.push_back(path);
        traverse(node->left, sum - node->val, result, path);
        traverse(node->right, sum - node->val, result, path);
        path.pop_back();
    }

    //与上面等价
    void traverse(TreeNode* node, int sum, vector<vector<int>>& result, vector<int>& path)
    {
        if(node == NULL)    return;
        path.push_back(node->val);
        if(!node->left && !node->right && sum == node->val)
        {
            result.push_back(path);
            path.pop_back();
            return;
        }
        traverse(node->left, sum - node->val, result, path);
        traverse(node->right, sum - node->val, result, path);
        path.pop_back();
    }
};