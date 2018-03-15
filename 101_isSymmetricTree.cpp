/*@Description: Symmetric Tree
Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).
For example, this binary tree [1,2,2,3,4,4,3] is symmetric:
    1
   / \
  2   2
 / \ / \
3  4 4  3
But the following [1,2,2,null,3,null,3] is not:
    1
   / \
  2   2
   \   \
   3    3
*/

/**
借助队列实现层序遍历（广度优先遍历），使用一个layer数组存储每一层的数据，对于左子结点或右子结点为空的情况，往数组中对应位置存0
（其实略有不妥，应该存一个不会出现的数据）。访问完上一层的结点后，下一层的结点全部进入队列，同时下一层的数据（包括部分空结点）也
全部存入数组，这时数组应该是前后对称的。至于要处理子结点为空的情况，是为了避免将上述第二个二叉树那样的结构认为是对称的。
*/
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(root == NULL)    return true;
        queue<TreeNode*> toVisit;
        toVisit.push(root);
        while(!toVisit.empty())
        {
            vector<int> layer;
            int size = toVisit.size();
            for(int i = 0; i < size; i++)
            {
                TreeNode* curr = toVisit.front();
                toVisit.pop();
                if(curr->left)  
                {
                    toVisit.push(curr->left);
                    layer.push_back(curr->left->val);
                }
                else    
                    layer.push_back(0);
                if(curr->right)
                {
                    toVisit.push(curr->right);
                    layer.push_back(curr->right->val);
                }
                else
                    layer.push_back(0);
            }
            for(int i = 0, j = layer.size() - 1; i < j; i++, j--)
                if(layer[i] != layer[j])
                    return false;
        }
        return true;
    }
};

//递归解法
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(root == NULL)    return true;
        return recursive(root->left, root->right);
    }
private:
    bool recursive(TreeNode* left, TreeNode* right)
    {
        if(left == NULL || right == NULL)
            return left == right;
        if(left->val != right->val)
            return false;
        return recursive(left->left, right->right) && recursive(left->right, right->left);
    }
};

/**
迭代解法，借助两个队列实现（栈也可以）
*/
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(root == NULL)    return true;
        queue<TreeNode*> q1, q2;
        q1.push(root->left);
        q2.push(root->right);
        while(!q1.empty() && !q2.empty())
        {
            TreeNode* left = q1.front();
            TreeNode* right = q2.front();
            q1.pop();
            q2.pop();
            if(left == NULL && right == NULL)
                continue;
            if(left == NULL || right == NULL)
                return false;
            if(left->val != right->val)
                return false;
            q1.push(left->left);	//入队列的顺序为左右
            q1.push(left->right);
            q2.push(right->right);	//入队列的顺序为右左
            q2.push(right->left);
        }
        return true;
    }
};