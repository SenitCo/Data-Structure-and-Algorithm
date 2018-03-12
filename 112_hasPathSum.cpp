/*@Description: Path Sum
Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up 
all the values along the path equals the given sum.
For example: Given the below binary tree and sum = 22,
              5
             / \
            4   8
           /   / \
          11  13  4
         /  \      \
        7    2      1
return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.
*/

//与此题类似(https://leetcode.com/problems/sum-root-to-leaf-numbers/description/)

//深度优先遍历，递归实现
class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if(!root)   return false;
        if(!root->left && !root->right && root->val == sum) return true;
        return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);
    }
};

//深度优先遍历，迭代（借助栈）实现
class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if(!root)   return false;
        stack<TreeNode*> toVisit;
        toVisit.push(root);
        int pathSum = 0;
        while(!toVisit.empty())
        {
            TreeNode* cur = toVisit.top();
            toVisit.pop();
            if(cur->right)
            {
                cur->right->val += cur->val;
                toVisit.push(cur->right);
            }
            if(cur->left)
            {
                cur->left->val += cur->val;
                toVisit.push(cur->left);
            }
            if(!cur->left && !cur->right)
            {
                if(cur->val == sum)
                    return true;
            }
        }
        return false;
    }
};

