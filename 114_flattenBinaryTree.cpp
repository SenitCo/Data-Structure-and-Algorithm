/*@Description: Flatten Binary Tree to Linked List
Given a binary tree, flatten it to a linked list in-place.
For example, Given

         1
        / \
       2   5
      / \   \
     3   4   6
The flattened tree should look like:
   1
    \
     2
      \
       3
        \
         4
          \
           5
            \
             6
*/

/**
迭代法：对任意一个结点curr，其左子树（如果存在）按先序遍历的最后一个结点的右子结点为curr的右子结点，
curr的右子结点为curr的左子结点
*/
class Solution {
public:
    void flatten(TreeNode* root) {
        TreeNode* curr = root;
        while(curr)
        {
            if(curr->left)
            {
                TreeNode* prev = curr->left;
                while(prev->right)
                    prev = prev->right; //遍历到左子树的最后一个结点，用于连接curr的右子树
                prev->right = curr->right;
                curr->right = curr->left;   //用当前结点的左子树替换右子树
                curr->left = NULL;
            }
            curr = curr->right; //往右移动结点
        }
    }
};

//递归法（先序遍历的逆转版本：右-左-中）
class Solution {
public:
    void flatten(TreeNode* root) {
        TreeNode* prev = NULL;
        reversePreorder(root, prev);
    }
private:
    //prev指针必须得传引用，保持更新，或者定义成一个成员变量
    void reversePreorder(TreeNode* node, TreeNode*& prev)   
    {
        if(node == NULL)    return;
        reversePreorder(node->right, prev);
        reversePreorder(node->left, prev);
        node->right = prev;
        node->left = NULL;
        prev = node;
    }
};