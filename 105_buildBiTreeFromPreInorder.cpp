/*@Description: Construct Binary Tree from Preorder and Inorder Traversal
Given preorder and inorder traversal of a tree, construct the binary tree.
Note: You may assume that duplicates do not exist in the tree.
For example, given preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
Return the following binary tree:
    3
   / \
  9  20
    /  \
   15   7
*/

/**递归法
对于先序中的第一个元素，找到中序中的对应元素的位置（可借助一个hash表直接存取，无需每次遍历），然后以该位置为中点，
将中序序列分成两部分递归进行，同时确定两个子序列的先序起点和终点
*/
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.empty())    return NULL;
        unordered_map<int, int> mp;
        for(int i = 0; i < inorder.size(); i++)
            mp[inorder[i]] = i;
        TreeNode* root = recursive(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1, mp);
        return root;
    }
private:
    TreeNode* recursive(vector<int>& preorder, vector<int>& inorder, int preStart, int preEnd, int inStart, int inEnd, unordered_map<int, int>& mp)
    {
        if(preStart > preEnd || inStart > inEnd)    return NULL;
        TreeNode* root = new TreeNode(preorder[preStart]);
        int inRoot = mp[root->val];
        int numLeft = inRoot - inStart;	//左子序列的长度
        root->left = recursive(preorder, inorder, preStart + 1, preStart + numLeft, inStart, inRoot - 1, mp);
        root->right = recursive(preorder, inorder, preStart + numLeft + 1, preEnd, inRoot + 1, inEnd, mp);
        return root;
    }
};

/**迭代法
使用两个变量i,j分别表示先序和中序的索引，并将先序中的元素依次压入栈中，进栈的同时依次生成每颗子树的左子结点，
直至栈顶元素和中序元素一致，说明该结点为某颗子树的根结点，这时应该为该结点插入右子结点，并将该该结点出栈。
*/
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.empty())    return NULL;
        stack<TreeNode*> st;
        TreeNode* root = new TreeNode(preorder[0]);
        st.push(root);
        int i = 1, j = 0, flag = 0;	//使用flag标记是插入左子结点还是右子结点
        TreeNode* t = root;
        while(i < preorder.size())
        {
            if(!st.empty() && st.top()->val == inorder[j])
            {
                t = st.top();
                st.pop();
                flag = 1;	//只有在回溯时（栈实现）遇到到子树的根结点才会右转生成右子结点
                j++;
            }
            else
            {
                if(flag == 0)
                {
                    t->left = new TreeNode(preorder[i]);
                    t = t->left;
                    st.push(t);
                    i++;
                }
                else
                {
                    flag = 0;	//每次插入右子结点重置flag标志
                    t->right = new TreeNode(preorder[i]);
                    t = t->right;
                    st.push(t);
                    i++;
                }
            }
        }
        return root;
    }
};



