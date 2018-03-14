/*@Description: Balanced Binary Tree
Given a binary tree, determine if it is height-balanced.
For this problem, a height-balanced binary tree is defined as:
a binary tree in which the depth of the two subtrees of every node never differ by more than 1.

Example 1: Given the following tree [3,9,20,null,null,15,7]:
    3
   / \
  9  20
    /  \
   15   7
Return true.

Example 2: Given the following tree [1,2,2,3,3,null,null,4,4]:

       1
      / \
     2   2
    / \
   3   3
  / \
 4   4
Return false.
*/

/**
自顶向下：判断每个结点左右子树的深度，如果深度差大于1，则返回false，否则继续考察其子结点是否为平衡树
*/
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if(root == NULL)    return true;
        int left = depth(root->left);
        int right = depth(root->right);
        if(abs(left - right) > 1)   return false;
        return isBalanced(root->left) && isBalanced(root->right);
    }
private:
    int depth(TreeNode* node)
    {
        if(node == NULL)    return 0;
        return max(depth(node->left), depth(node->right)) + 1;
    }
};

/**
自底向上，后序遍历（左-右-中），从叶子结点开始计算每个结点的高度，并判断左右子树的高度差是否大于1，
若大于1则递归返回1，否则进一步判断其他结点是否为平衡树。（相比于自顶向下，该方法更高效）
*/
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if(root == NULL)    return true;
        return dfsHeight(root) != -1;
    }
private:
    int dfsHeight(TreeNode* node)
    {
        if(node == NULL)    return 0;
        int left = dfsHeight(node->left);
        if(left == -1)  return -1;
        int right = dfsHeight(node->right);
        if(right == -1) return -1;
        if(abs(left - right) > 1)   return -1;
        return max(left, right) + 1;
    }
};