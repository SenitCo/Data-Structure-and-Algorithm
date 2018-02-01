/*@Description: Binary Tree Postorder Traversal
Given a binary tree, return the postorder traversal of its nodes' values.
For example: Given binary tree [1,null,2,3], return [3,2,1].
   1
    \
     2
    /
   3
Note: Recursive solution is trivial, could you do it iteratively?
*/

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/**
递归法
*/
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        traverse(root, result);
        return result;
    }
private:
    void traverse(TreeNode* node, vector<int>& result)
    {
        if(!node)    return;
        traverse(node->left, result);
        traverse(node->right, result);
        result.push_back(node->val);
    }
};

/**
迭代法：后序遍历是左-右-根，将其转换为根-右-左（实现方法和先序遍历根-左-右类似，只是左右互换），
最后将数组逆转即可
*/
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> toVisit;
        while(root != NULL || !toVisit.empty())
        {
            while(root)
            {
                result.push_back(root->val);
                toVisit.push(root);
                root = root->right;
            }
            root = toVisit.top();
            toVisit.pop();
            root = root->left;
        }
        reverse(result.begin(), result.end());
        return result;
    }
};

/**
和上述迭代解法一致，只是将while循环替换成了if else
*/
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> toVisit;
        while(root != NULL || !toVisit.empty())
        {
            if(root)
            {
                result.push_back(root->val);
                toVisit.push(root);
                root = root->right;
            }
            else
            {
                root = toVisit.top();
                toVisit.pop();
                root = root->left;
            }
        }
        reverse(result.begin(), result.end());
        return result;
    }
};

/**
按根-右-左的顺序遍历，然后逆转
*/
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        if(!root)   return result;
        stack<TreeNode*> toVisit;
        toVisit.push(root);
        while(!toVisit.empty())
        {
            root = toVisit.top();
            toVisit.pop();
            result.push_back(root->val);
            if(root->left)  		//注意此处要先将左子结点压入栈中
                toVisit.push(root->left);
            if(root->right)
                toVisit.push(root->right);
        }
        reverse(result.begin(), result.end());
        return result;
    }
};