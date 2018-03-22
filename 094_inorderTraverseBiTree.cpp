/*@Description: Binary Tree Inorder Traversal
Given a binary tree, return the inorder traversal of its nodes' values.
For example: Given binary tree [1,null,2,3],
   1
    \
     2
    /
   3
return [1,3,2].
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        InOrderTraverse(root, result);
        return result;
    }
private:
    void InOrderTraverse(TreeNode* node, vector<int>& result)
    {
        if(node == NULL)    return;
        InOrderTraverse(node->left, result);
        result.push_back(node->val);
        InOrderTraverse(node->right, result);
    }
};

/**
迭代法
*/
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> nodes;
        stack<TreeNode*> toVisit;
        TreeNode* curNode = root;
        while (curNode || !toVisit.empty()) {
            if (curNode) {
                toVisit.push(curNode);
                curNode = curNode -> left;
            }
            else {
                curNode = toVisit.top();
                toVisit.pop();
                nodes.push_back(curNode -> val);
                curNode = curNode -> right;
            }
        }
        return nodes;
    }
};

/**
迭代法
*/
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> nodes;
        std::stack<TreeNode*> toVisit;
        while(1) {
            while(root) 
            { 
                toVisit.push(root); 
                root = root->left; 
            }
            if(toVisit.empty()) break;
            root = toVisit.top(); 
            toVisit.pop();
            nodes.push_back(root->val);
            root = root->right;
        }
        return nodes;
    }
};