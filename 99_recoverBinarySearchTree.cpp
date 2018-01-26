/*@Description: Recover Binary Search Tree
Two elements of a binary search tree (BST) are swapped by mistake.
Recover the tree without changing its structure.
Note: A solution using O(n) space is pretty straight forward. Could you devise a constant space solution?
*/

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/**
递归法中序遍历，对于异常点，存在前一个元素大于后一个元素，但两个异常点略有差异（第一个异常点，
其值大于后一个元素；第二个异常点，其值小于前一个元素）
*/
class Solution {
public:
    void recoverTree(TreeNode* root) {
        inorderTraverse(root);
        int temp = first->val;
        first->val = second->val;
        second->val = temp;
    }
private:
    TreeNode *first = NULL, *second = NULL;	//如果不定义为成员变量，而是作为形参，则应该传指针变量的引用
    TreeNode *prev = new TreeNode(INT_MIN);
    void inorderTraverse(TreeNode* root)
    {
        if(!root)   return;
        inorderTraverse(root->left);
        if(first == NULL && prev->val >= root->val)
            first = prev;
        if(first != NULL && prev->val >= root->val)
            second = root;
        prev = root;
        inorderTraverse(root->right);
    }
};

/**
迭代法中序遍历
*/
class Solution {
public:
    void recoverTree(TreeNode* root) {
        TreeNode *first = NULL, *second = NULL;
        TreeNode *prev = new TreeNode(INT_MIN);
        stack<TreeNode*> toVisit;
        while(root != NULL || !toVisit.empty())
        {
            while(root)
            {
                toVisit.push(root);
                root = root->left;
            }
            root = toVisit.top();
            toVisit.pop();
            if(first == NULL && prev->val >= root->val)
                first = prev;
            if(first != NULL && prev->val >= root->val)
                second = root;
            prev = root;
            root = root->right;
        }
        
        int temp = first->val;
        first->val = second->val;
        second->val = temp;
    }
};