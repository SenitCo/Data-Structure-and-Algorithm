/*@Description: Populating Next Right Pointers in Each Node II
Follow up for problem "Populating Next Right Pointers in Each Node".
What if the given tree could be any binary tree? Would your previous solution still work?
Note: You may only use constant extra space.
For example, Given the following binary tree,
         1
       /  \
      2    3
     / \    \
    4   5    7
After calling your function, the tree should look like:
         1 -> NULL
       /  \
      2 -> 3 -> NULL
     / \    \
    4-> 5 -> 7 -> NULL
*/

//Definition for binary tree with next pointer.
struct TreeLinkNode {
    int val;
    TreeLinkNode *left, *right, *next;
    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

/**
层序遍历
*/
class Solution {
public:
    void connect(TreeLinkNode *root) {
        TreeLinkNode *head = root;  //下一层最左边的结点（起始有效结点）
        TreeLinkNode *curr = NULL;  //上一层中的当前结点
        TreeLinkNode *prev = NULL;  //下一层中前一个结点（用于连接当前结点的左子结点或右子结点作为其下一个结点）
        while(head)
        {
            curr = head;
            head = prev = NULL;
            while(curr)
            {
                if(curr->left)      
                {
                    if(prev)
                        prev->next = curr->left;    //给前一个结点的next指针赋值
                    else
                        head = curr->left;  //如果前一个结点不存在，则给起始结点赋值
                    prev = curr->left;      //更新前一个结点
                }
                if(curr->right)
                {
                    if(prev)
                        prev->next = curr->right;
                    else
                        head = curr->right;
                    prev = curr->right;
                }
                curr = curr->next;
            }
        }
    }
};