/*@Description: Binary Tree Preorder Traversal
Given a binary tree, return the preorder traversal of its nodes' values.
For example: Given binary tree [1,null,2,3], return [1,2,3].
   1
    \
     2
    /
   3
Note: Recursive solution is trivial, could you do it iteratively?
*/

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        traverse(root, result);
        return result;
    }
private:
    void traverse(TreeNode* node, vector<int>& result)
    {
        if(!node)	return;
        result.push_back(node->val);
        traverse(node->left, result);
        traverse(node->right, result);
    }
};


class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode*> toVisit;
        vector<int> result;
        while(root != NULL || !toVisit.empty())
        {
            while(root)
            {
                result.push_back(root->val);
                toVisit.push(root);
                root = root->left;
            }
            root = toVisit.top();
            toVisit.pop();
            root = root->right;
        }
        return result;
    }
};

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        if(!root)   return result;
        stack<TreeNode*> toVisit;
        toVisit.push(root);
        while(!toVisit.empty())
        {
            root = toVisit.top();
            toVisit.pop();
            result.push_back(root->val);    
            if(root->right)
                toVisit.push(root->right);  //注意此处要先将右子结点压入栈中
            if(root->left)
                toVisit.push(root->left);
        }
        return result;
    }
};