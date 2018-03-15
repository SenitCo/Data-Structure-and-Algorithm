/*@Description: Binary Tree Level Order Traversal II
Given a binary tree, return the bottom-up level order traversal of its nodes' values. 
(ie, from left to right, level by level from leaf to root).
For example: Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its bottom-up level order traversal as:
[
  [15,7],
  [9,20],
  [3]
]
*/

/**
递归先序遍历，然后反转
*/
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> result;
        preorderDFS(result, root, 0);
        reverse(result.begin(), result.end());
        return result;
    }
private:
    void preorderDFS(vector<vector<int>>& result, TreeNode* node, int depth)
    {
        if(node == NULL)    return;
        if(result.size() == depth)
            result.push_back(vector<int>());
        result[depth].push_back(node->val);
        preorderDFS(result, node->left, depth + 1);
        preorderDFS(result, node->right, depth + 1);
    }
};

/**
借助队列实现广度优先遍历，然后反转
*/
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> result;
        if(root == NULL)    return result;
        queue<TreeNode*> toVisit;
        toVisit.push(root);
        while(!toVisit.empty())
        {
            int size = toVisit.size();
            vector<int> layer;
            for(int i = 0; i < size; i++)
            {
                TreeNode* curr = toVisit.front();
                toVisit.pop();
                if(curr->left)  toVisit.push(curr->left);
                if(curr->right) toVisit.push(curr->right);
                layer.push_back(curr->val);
            }
            result.push_back(layer);
        }
        reverse(result.begin(), result.end());
        return result;
    }
};