/*@Description: Construct Binary Tree from Inorder and Postorder Traversal
Given inorder and postorder traversal of a tree, construct the binary tree.
Note: You may assume that duplicates do not exist in the tree.
For example, given inorder = [9,3,15,20,7], postorder = [9,15,7,20,3]
Return the following binary tree:
    3
   / \
  9  20
    /  \
   15   7
*/

/**递归法
对于后序（左-右-中）中的最后一个元素，找到中序中的对应元素的位置（可借助一个hash表直接存取，无需每次遍历），然后以该位置为中点，
将中序序列分成两部分递归进行，同时确定两个子序列的后序起点和终点
*/
class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.empty()) return NULL;
        unordered_map<int, int> mp;
        for(int i = 0;i < inorder.size(); i++)
            mp[inorder[i]] = i;
        TreeNode* root = recursive(inorder, postorder, 0, inorder.size() - 1, 0, postorder.size() - 1, mp);
        return root;
    }
private:
    TreeNode* recursive(vector<int>& inorder, vector<int>& postorder, int inStart, int inEnd, int postStart, int postEnd, unordered_map<int, int>& mp)
    {
        if(inStart > inEnd || postStart > postEnd)  return NULL;
        TreeNode* node = new TreeNode(postorder[postEnd]);	//后序序列的最后一个结点
        int inRoot = mp[node->val];
        int numLeft = inRoot - inStart;
        node->left = recursive(inorder, postorder, inStart, inRoot - 1, postStart, postStart + numLeft - 1, mp);
        node->right = recursive(inorder, postorder, inRoot + 1, inEnd, postStart + numLeft, postEnd - 1, mp);
        return node;
    }
};

/**迭代法
使用两个变量i,j分别表示后序和中序的索引，并依次从后往前遍历后序和中序序列。将后序中的元素从后往前压入栈中，进栈的同时依次生成
每颗子树的右子结点，直至栈顶元素和中序元素一致，说明该结点为某颗子树的根结点，这时应该为该结点插入左子结点，并将该该结点出栈。
*/
class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.empty()) return NULL;
        stack<TreeNode*> st;
        int size = inorder.size();
        TreeNode* root = new TreeNode(postorder[size - 1]);
        st.push(root);
        TreeNode* t = root;
        int i = size - 2, j = size - 1, flag = 0;	//使用flag标记是插入左子结点还是右子结点
        while(i >= 0)
        {
            if(!st.empty() && st.top()->val == inorder[j])
            {
                t = st.top();
                st.pop();
                flag = 1;		//只有在回溯时（栈实现）遇到到子树的根结点才会左转生成左子结点
                j--;
            }
            else
            {
                if(flag == 0)
                {
                    t->right = new TreeNode(postorder[i]);
                    t = t->right;
                    st.push(t);
                    i--;
                }
                else
                {
                    flag = 0;		//每次插入左子结点重置flag标志
                    t->left = new TreeNode(postorder[i]);
                    t = t->left;
                    st.push(t);
                    i--;
                }
            }
        }
        return root;
    }
};