/*@Description: Sum Root to Leaf Numbers
Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.
An example is the root-to-leaf path 1->2->3 which represents the number 123.
Find the total sum of all root-to-leaf numbers.
For example,
    1
   / \
  2   3
The root-to-leaf path 1->2 represents the number 12.
The root-to-leaf path 1->3 represents the number 13.
Return the sum = 12 + 13 = 25.
*/

//递归法
class Solution {
public:
    int sumNumbers(TreeNode* root) {
        return sum(root, 0);
    }
private:
    int sum(TreeNode* node, int s)
    {
        if(!node)   return 0;
        if(!node->left && !node->right)
            return s * 10 + node->val;
        return sum(node->left, s * 10 + node->val) + sum(node->right, s * 10 + node->val);
    }
};

//迭代法
class Solution {
public:
    int sumNumbers(TreeNode* root) {
        if(!root)   return 0;
        int sum = 0;
        stack<TreeNode*> toVisit;
        toVisit.push(root);
        while(!toVisit.empty())
        {
            TreeNode* cur = toVisit.top();
            toVisit.pop();
            if(cur->right)
            {
                cur->right->val = cur->val * 10 + cur->right->val;
                toVisit.push(cur->right);
            }
            if(cur->left)
            {
                cur->left->val = cur->val * 10 + cur->left->val;
                toVisit.push(cur->left);
            }
            if(!cur->left && !cur->right)
            {
                sum += cur->val;
            }
        }
        return sum;
    }
};