/*@Description: Linked List Cycle
Given a linked list, determine if it has a cycle in it.
Follow up: Can you solve it without using extra space?
*/

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

/**
借助两个指针，分别从头结点出发，一个指针每次移动一个步长，另一个指针每次移动两个步长，
如果存在环，则两个指针必在环内相遇。
*/
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(!head || !head->next)
            return NULL;
        ListNode *p1, *p2;
        p1 = p2 = head;
        while(p2 && p2->next)
        {
            p1 = p1->next;
            p2 = p2->next->next;
            if(p1 == p2)  
                return true;
        }
        return false;
    }
};