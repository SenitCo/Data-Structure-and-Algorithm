/*@Description: Same Tree
Given two binary trees, write a function to check if they are the same or not.
Two binary trees are considered the same if they are structurally identical and the nodes have the same value.

Example 1:
Input:     1         1
          / \       / \
         2   3     2   3
        [1,2,3],   [1,2,3]
Output: true

Example 2:
Input:     1         1
          /           \
         2             2
        [1,2],     [1,null,2]
Output: false

Example 3:
Input:     1         1
          / \       / \
         2   1     1   2
        [1,2,1],   [1,1,2]
Output: false
*/

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/**
递归法中序遍历，对于这种判断真假的递归，与一般的递归遍历相比有些特殊，因为在遍历过程中，
如果不符合条件，则终止递归直接返回false，而最终的结果若要返回true，则需完整遍历一次，且
遍历过程中所有判断条件都要为真
*/
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return traverse(p, q);
    }
private:
    bool traverse(TreeNode* p, TreeNode* q)
    {
        if(p == NULL && q == NULL)  return true;
        else if((p && !q) || (!p && q)) return false;
        if(!traverse(p->left, q->left)) return false;
        if (p->val != q->val)
            return false;
        return traverse(p->right, q->right);
    }
};

/**
递归法先序遍历
*/
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == NULL && q == NULL) return true;
        if(p == NULL || q == NULL) return false;
        if(p->val == q->val)
            return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
        return false;
    }
};