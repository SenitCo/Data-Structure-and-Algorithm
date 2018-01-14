/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

//遍历一次链表，判断相邻节点是否相等
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *pNode = head;
        ListNode *pNext = pNode;
        while(pNode)
        {
            pNext = pNode->next;
            if(pNext && pNode->val == pNext->val)
            {
                pNode->next = pNext->next;
                delete pNext;
            }
            else
                pNode = pNext;
        }
        return head;
    }
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *pNode = head;
        while(pNode)
        {
            if(pNode->next && pNode->val == pNode->next->val)
            {
                pNode->next = pNode->next->next;
                //delete pNext;
            }
            else
                pNode = pNode->next;
        }
        return head;
    }
};