/*@Description: Remove Nth Node From End of List
Given a linked list, remove the nth node from the end of list and return its head.

For example,

   Given linked list: 1->2->3->4->5, and n = 2.

   After removing the second node from the end, the linked list becomes 1->2->3->5.
Note:
Given n will always be valid.
Try to do this in one pass.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* start = new ListNode(0);			//加一个起始（首）结点可有效解决只有一个元素的情况
        ListNode *front = start, *back = start;
        back->next = head;
        for(int i = 0; i < n + 1; i++)
        {
            front = front->next;
        }
        while(front)
        {
            front = front->next;
            back = back->next;
        }
        back->next = back->next->next;
        return start->next;
    }
};