/*@Description: Linked List Cycle II
Given a linked list, return the node where the cycle begins. If there is no cycle, return null.
Note: Do not modify the linked list.
Follow up: Can you solve it without using extra space?
*/

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

/**
借助两个指针，分别从头结点出发，一个指针每次移动一个步长，另一个指针每次移动两个步长，如果存在环，
则两个指针必在环内相遇。然后另一个指针指向链表头结点，另一个指针仍位于相遇点，然后均以单步长移动指针，
再次相遇点即为环的起始点。设第一次相遇点距离链表起点为k，环起始点距离链表起点为s，环起始点到第一次
相遇点距离为m，环长度为r，则有k = s + m, 且2k - k = nr = k, 即 s = nr - m。
*/
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(!head || !head->next)
            return NULL;
        ListNode *p1, *p2;
        p1 = p2 = head;
        bool flag = false;
        while(p2 && p2->next)
        {
            p1 = p1->next;
            p2 = p2->next->next;
            if(p1 == p2)  
            {
                flag = true;
                break;
            }
        }
        if(!flag)   return NULL;
        
        p1 = head;
        while(p1 != p2)
        {
            p1 = p1->next;
            p2 = p2->next;
        }
        return p1;
        
    }
};