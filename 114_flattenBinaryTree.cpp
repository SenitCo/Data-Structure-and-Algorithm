/*@Description: Flatten Binary Tree to Linked List
Given a binary tree, flatten it to a linked list in-place.
For example, Given

         1
        / \
       2   5
      / \   \
     3   4   6
The flattened tree should look like:
   1
    \
     2
      \
       3
        \
         4
          \
           5
            \
             6
*/

class Solution {
public:
    void flatten(TreeNode* root) {
        TreeNode* curr = root;
        while(curr)
        {
            if(curr->left)
            {
                TreeNode* prev = curr->left;
                while(prev->right)
                    prev = prev->right;
                prev->right = curr->right;
                curr->right = curr->left;
                curr->left = NULL;
            }
            curr = curr->right;
        }
    }
};