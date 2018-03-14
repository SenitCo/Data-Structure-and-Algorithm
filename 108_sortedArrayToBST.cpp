/*@Description: Convert Sorted Array to Binary Search Tree
Given an array where elements are sorted in ascending order, convert it to a height balanced BST.
For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of 
the two subtrees of every node never differ by more than 1.
Example: Given the sorted array: [-10,-3,0,5,9],
One possible answer is: [0,-3,9,-10,null,5], which represents the following height balanced BST:
      0
     / \
   -3   9
   /   /
 -10  5
*/

//递归二分，将中点值置于合适的树结点中
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        TreeNode* root = NULL;
        partition(root, nums, 0, nums.size() - 1);
        return root;
    }
private:
    void partition(TreeNode*& node, vector<int>& nums, int left, int right)
    {
        if(left > right)    return;
        int mid = (left + right) / 2;
        node = new TreeNode(nums[mid]);
        partition(node->left, nums, left, mid - 1);
        partition(node->right, nums, mid + 1, right);
    }
};