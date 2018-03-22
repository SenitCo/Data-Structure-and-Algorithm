/*@Description: Swap Nodes in Pairs
Given a linked list, swap every two adjacent nodes and return its head.

For example,
Given 1->2->3->4, you should return the list as 2->1->4->3.

Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed.
*/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

/*遍历链表元素，两两交换，但要注意将前后元素合理链接起来*/
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (!head)
            return nullptr;
        ListNode *p = head, *t = head->next, *s = t;
        ListNode *start = head;
        if (head->next)
            start = head->next;
        while (p && t)
        {
            s = t;
            t = p;
            t->next = s->next;
            p = s;
            p->next = t;

            p = t->next;
            if (p)
            {
                if (p->next)
                    t->next = p->next;  //关键步骤，否则链表是跨节点连接，只有一半
                t = p->next;
            }
            else
                break;

        }
        return start;
    }
};

/*遍历元素，两两交换*/
ListNode* swapPairs(ListNode* head) 
{
    ListNode* start = new ListNode(0);
    start->next = head;
    ListNode* current = start;
    ListNode *first, *second;
    while(current->next && current->next->next)
    {
        first = current->next;
        second = first->next;
        first->next = second->next;
        current->next = second;
        second->next = first;
        current = current->next->next;
    }
    return start->next;
}

/*递归法*/
ListNode* swapPairs(ListNode* head) 
{
    if(head == nullptr || head->next == nullptr)
        return head;
    ListNode* pNode = head->next;
    head->next = swapPairs(head->next->next);
    pNode->next = head;
    return pNode;
}

/*二级指针*/
ListNode* swapPairs(ListNode* head) 
{
    ListNode **pp = &head, *a, *b;
    while ((a = *pp) && (b = a->next)) 
    {
        a->next = b->next;
        b->next = a;
        *pp = b;    //改变指针指指向的地址
        pp = &(a->next);
    }
    return head;
}