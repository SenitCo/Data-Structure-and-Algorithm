/*@Description: Validate Binary Search Tree
Given a binary tree, determine if it is a valid binary search tree (BST).
Assume a BST is defined as follows:
The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
Example 1:
    2
   / \
  1   3
Binary tree [2,1,3], return true.
Example 2:
    1
   / \
  2   3
Binary tree [1,2,3], return false.
*/

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/**
迭代法中序遍历，对于合法二叉搜索树，中序遍历的结果为递增关系
*/
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if(root == NULL)    return true;
        TreeNode* prev = NULL;
        stack<TreeNode*> toVisit;
        while(root != NULL || !toVisit.empty())
        {
            while(root != NULL)
            {
                toVisit.push(root);
                root = root->left;
            }
            root = toVisit.top();
            toVisit.pop();
            if(prev != NULL && root->val <= prev->val)
                return false;
            prev = root;
            root = root->right;
        }
        return true;
    }
};

/**
递归法中序遍历
*/
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        TreeNode* prev = NULL;
        return isValid(root, prev);
    }
private:
    bool isValid(TreeNode* node, TreeNode* &prev)
    {
        if(node == NULL)    return true;
        if(!isValid(node->left, prev))   return false;
        if(prev != NULL && prev->val >= node->val)
            return false;
        prev = node;
        return isValid(node->right, prev);
    }
};