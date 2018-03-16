/*@Description: Binary Tree Zigzag Level Order Traversal
Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, 
then right to left for the next level and alternate between).
For example: Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its zigzag level order traversal as:
[
  [3],
  [20,9],
  [15,7]
]
*/

//队列实现层序遍历
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if(root == NULL)    return result;
        queue<TreeNode*> toVisit;
        toVisit.push(root);
        bool leftToRight = true;    //用一个变量表示每一层遍历时存储的顺序
        while(!toVisit.empty())
        {
            int size = toVisit.size();
            vector<int> layer(size);
            for(int i = 0; i < size; i++)
            {
                TreeNode* curr = toVisit.front();
                toVisit.pop();
                int index = leftToRight ? i : size - 1 - i;
                layer[index] = curr->val;
                if(curr->left)  toVisit.push(curr->left);
                if(curr->right) toVisit.push(curr->right);
            }
            result.push_back(layer);
            leftToRight = !leftToRight;
        }
        return result;
    }
};