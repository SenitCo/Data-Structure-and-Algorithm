/*@Description: Binary Tree Maximum Path Sum
Given a binary tree, find the maximum path sum.
For this problem, a path is defined as any sequence of nodes from some starting node to any node 
in the tree along the parent-child connections. The path must contain at least one node and does 
not need to go through the root.
*/

/**
要求二叉树中任意两个结点之间最大路径和，而不是从根结点出发到某一子结点的最大路径和。可采用深度优先遍历求解，
只不过递归函数的返回值不是要求的最大和（最大和通过一个全局变量或者引用参数来同步更新），而是结点自身为根结点
时到其子结点的最大路径，该值用于提供给其父结点计算最长路径（当其父节点为根结点时，下面的子结点只能是单向的）。
简单来说，一个结点的最大路径和是其左子树路径和 + 右子树路径和 + 当前节点值，而返回值则是当前结点值加上左子树
路径和与右子树路径和的较大值。考虑负数的影响，加入与0的比较。
*/
class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int maxVal = INT_MIN;
        maxPathDown(maxVal, root);
        return maxVal;
    }
    int maxPathDown(int& maxVal, TreeNode* node)
    {
        if(!node)   return 0;
        int left = max(0, maxPathDown(maxVal, node->left));     //与0比较考虑了负数的影响
        int right = max(0, maxPathDown(maxVal, node->right));
        maxVal = max(maxVal, left + right + node->val);
        return max(left, right) + node->val;
    }
};
