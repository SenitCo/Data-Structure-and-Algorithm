/*@Description: Unique Binary Search Trees II
Given an integer n, generate all structurally unique BST's (binary search trees) that store values 1...n.
For example, Given n = 3, your program should return all 5 unique BST's shown below.

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
*/


//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/**
递归解法
*/
class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        if(n == 0)  return vector<TreeNode*>();
        return generateBST(1, n);
    }
private:
    vector<TreeNode*> generateBST(int start, int end)
    {
        vector<TreeNode*> result;
        if(start > end)
            result.push_back(NULL);
        vector<TreeNode*> left, right;
        for(int i = start; i <= end; i++)
        {
            left = generateBST(start, i - 1);
            right = generateBST(i + 1, end);
            for(auto lnode : left)
            {
                for(auto rnode: right)
                {
                    TreeNode* root = new TreeNode(i);
                    root->left = lnode;
                    root->right = rnode;
                    result.push_back(root);
                }
            }
        }
        return result;
    }
};