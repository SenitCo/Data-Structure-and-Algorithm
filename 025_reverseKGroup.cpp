/*@Description: Reverse Nodes in k-Group
Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.
k is a positive integer and is less than or equal to the length of the linked list. If the number 
of nodes is not a multiple of k then left-out nodes in the end should remain as it is.
You may not alter the values in the nodes, only nodes itself may be changed.
Only constant memory is allowed.

For example,
Given this linked list: 1->2->3->4->5
For k = 2, you should return: 2->1->4->3->5
For k = 3, you should return: 3->2->1->4->5
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

/**
-1 -> 1 -> 2 -> 3 -> 4 -> 5
 |    |    |     
pre  cur  nex  

-1 -> 2 -> 1 -> 3 -> 4 -> 5
 |         |    |     
pre       cur  nex  

-1 -> 3 -> 2 -> 1 -> 4 -> 5
 |              |    |    
pre            cur  nex 

三个重要元素，头指针pre，始终指向已重新排列的第一个元素；当前指针cur，指向已排序的最后一个元素；
cur->next则指向未排序的第一个元素也就是nex指针，nex的作用是即将作为第一个元素赋给pre->next.
*/
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == nullptr || k == 1)
            return head;
        int num = 0;
        ListNode* preheader = new ListNode(0);
        ListNode *pre, *nex, *cur;
        preheader->next = head;
        cur = pre = preheader;
        while(cur = cur->next)
            num++;
        while(num >= k)
        {
            cur = pre->next;
            nex = cur->next;
            for(int i = 1; i < k; i++)
            {
                cur->next = nex->next;
                nex->next = pre->next;
                pre->next = nex;
                nex = cur->next;
            }
            pre = cur;
            num -= k;
        }
        return preheader->next;
    }
};

/**递归解法：
head：指向正序起始节点
curr：指向反转后的起始节点
tmp：head->next，用于保存下一个插入反转序列的节点
*/
ListNode* reverseKGroup(ListNode* head, int k) 
{
    ListNode* curr = head;
    int count = 0;
    while (curr != nullptr && count != k) { // find the k+1 node
        curr = curr->next;
        count++;
    }
    if (count == k) { // if k+1 node is found
        curr = reverseKGroup(curr, k); // reverse list with k+1 node as head
        // head - head-pointer to direct part, 
        // curr - head-pointer to reversed part;
        while (count-- > 0) { // reverse current k-group: 
            ListNode* tmp = head->next; // tmp - next head in direct part
            head->next = curr; // preappending "direct" head to the reversed list 
            curr = head; // move head of reversed part to a new node
            head = tmp; // move "direct" head to the next node in direct part
        }
        head = curr;
    }
    return head;
}