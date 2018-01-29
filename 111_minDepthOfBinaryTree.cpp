/*@Description: Minimum Depth of Binary Tree
Given a binary tree, find its minimum depth. The minimum depth is the number of nodes 
along the shortest path from the root node down to the nearest leaf node.
*/

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/**
递归遍历
*/
class Solution {
public:
    int minDepth(TreeNode* root) {
        int depth = 1, minDepth = INT_MAX;
        if(!root)   return 0;
        traverse(root, depth, minDepth);
        return minDepth;
    }
private:
    void traverse(TreeNode* node, int depth, int& minDepth)
    {
        if(node == NULL)
            return;
        if(!node->left && !node->right)
        {
            if(depth < minDepth)
                minDepth = depth;
            return;
        }   
        traverse(node->left, depth + 1, minDepth);
        traverse(node->right, depth + 1, minDepth);  
    }
};

class Solution {
public:
    int minDepth(TreeNode* root) {
        if(!root)
            return 0;
        int l = minDepth(root->left);
        int r = minDepth(root->right);
        if(l == 0 || r == 0)
            return 1 + l + r;
        return 1 + min(l, r);
        
    }
};

/**
广度优先遍历（层序遍历），找到的第一个叶节点的深度即是最浅，不需要遍历所有结点
*/
class Solution {
public:
    int minDepth(TreeNode* root) {
        if(!root) return 0;
        queue<TreeNode*> qu;
        TreeNode *last, *now;
        int level, size;
        last = now = root;
        level = 1;
        qu.push(root);
        while(qu.size())
        {
            now = qu.front();
            qu.pop();
            size = qu.size();
            if(now->left)	qu.push(now->left);
            if(now->right)	qu.push(now->right);
            if(qu.size() == size)	break;
            if(last == now)
            {
                level++;
                if(qu.size())
                    last = qu.back();
            }
        }
        return level;      
    }
};