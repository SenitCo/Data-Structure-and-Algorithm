/*@Description: Maximum Depth of Binary Tree
Given a binary tree, find its maximum depth. The maximum depth is the number of nodes along the longest path from 
the root node down to the farthest leaf node.
For example: Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its depth = 3.
*/

//队列实现层序遍历（广度优先遍历）
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == NULL)    return 0;
        queue<TreeNode*> toVisit;
        toVisit.push(root);
        int depth = 0;
        while(!toVisit.empty())
        {
            int size = toVisit.size();
            for(int i = 0; i < size; i++)
            {
                TreeNode* curr = toVisit.front();
                toVisit.pop();
                if(curr->left)  toVisit.push(curr->left);
                if(curr->right) toVisit.push(curr->right);
            }
            depth++;
        }
        return depth;
    }
};

//中序遍历
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(!root)   return 0;
        int depth = 1, maxDepth = 0;
        traverse(root, depth, maxDepth);
        return maxDepth;
    }
private:
    void traverse(TreeNode* node, int depth, int& maxDepth)
    {
        if(node == NULL)
            return;
        if(!node->left && !node->right)
        {
            if(depth > maxDepth)
                maxDepth = depth;
            return;
        }   
        traverse(node->left, depth + 1, maxDepth);
        traverse(node->right, depth + 1, maxDepth);  
    }
};

//递归遍历（深度优先遍历）
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == NULL)  return 0;
        return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }
};