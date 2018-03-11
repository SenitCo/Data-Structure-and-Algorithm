/*@Description: Populating Next Right Pointers in Each Node
Given a binary tree
    struct TreeLinkNode {
      TreeLinkNode *left;
      TreeLinkNode *right;
      TreeLinkNode *next;
    }
Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.
Initially, all next pointers are set to NULL.
Note:
You may only use constant extra space.
You may assume that it is a perfect binary tree (ie, all leaves are at the same level, and every parent has two children).
For example, Given the following perfect binary tree,
         1
       /  \
      2    3
     / \  / \
    4  5  6  7
After calling your function, the tree should look like:
         1 -> NULL
       /  \
      2 -> 3 -> NULL
     / \  / \
    4->5->6->7 -> NULL
*/

//Definition for binary tree with next pointer.
struct TreeLinkNode {
    int val;
    TreeLinkNode *left, *right, *next;
    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

/**
借助队列实现广度优先遍历，但空间复杂度不是常量存储
*/
class Solution {
public:
    void connect(TreeLinkNode *root) {
        queue<TreeLinkNode*> toVisit;
        if(!root)   return;
        toVisit.push(root);
        while(!toVisit.empty())
        {
            int size = toVisit.size();
            TreeLinkNode* cur = toVisit.front();
            if(!cur)  return;
            toVisit.pop();
            toVisit.push(cur->left);
            toVisit.push(cur->right);
            TreeLinkNode* next;
            for(int i = 0; i < size - 1; i++)
            {
                
                next = toVisit.front();
                toVisit.pop();
                cur->next = next;
                toVisit.push(next->left);
                toVisit.push(next->right);
                cur = next;
            }
        }
        return;
    }
};

class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(!root)   return;
        TreeLinkNode *pre = root, *cur = NULL;
        while(pre->left)
        {
            cur = pre;
            while(cur)
            {
                cur->left->next = cur->right;
                if(cur->next)
                    cur->right->next = cur->next->left;
                cur = cur->next;
            }
            pre = pre->left;
        }
    }
};