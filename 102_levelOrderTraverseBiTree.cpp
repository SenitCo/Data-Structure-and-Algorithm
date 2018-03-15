/*@Description: Binary Tree Level Order Traversal
Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).
For example: Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its level order traversal as:
[
  [3],
  [9,20],
  [15,7]
]
*/

/**
借助队列实现广度优先遍历
*/
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if(root == NULL)    return result;
        queue<TreeNode*> toVisit;
        toVisit.push(root);
        while(!toVisit.empty())
        {
            int size = toVisit.size();
            vector<int> layer;
            for(int i = 0; i < size; i++)	//区分每一层的数据
            {
                TreeNode* curr = toVisit.front();
                toVisit.pop();
                if(curr->left)  toVisit.push(curr->left);
                if(curr->right) toVisit.push(curr->right);
                layer.push_back(curr->val);
            }
            result.push_back(layer);
        }
        return result;
    }
};

/**
深度优先遍历（先序遍历），借助一个变量表示当前的层数，如此遍历顺序不再关键
*/
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        preorderDFS(result, root, 0);
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
