/*@Description
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.
You may assume the two numbers do not contain any leading zero, except the number 0 itself
*/

 /*Definition for singly-linked list.*/
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution1 {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *pL1 = l1, *pL2 = l2;
        ListNode* result = new ListNode(0), *pResult = result;
        int value = 0, preStep = 0, nextStep = 0;
        while(pL1 || pL2)
        {
            preStep = nextStep;
            nextStep = 0;
            if(!pL1)
            {
                value = pL2->val + preStep;
                pL2 = pL2->next;
            }
            else if(!pL2)
            {
                value = pL1->val + preStep;
                pL1 = pL1->next;
            }   
            else
            {
                value = pL1->val + pL2->val + preStep;
                pL1 = pL1->next;
                pL2 = pL2->next;
            }
            if(value > 9)
            {
                value -= 10;
                nextStep = 1;
            }
            pResult->next = new ListNode(value);
            pResult = pResult->next;
        }
        if(nextStep > 0)
            pResult->next = new ListNode(nextStep);
        result = result->next;
        return result;
    }
};

class Solution2 {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *pL1 = l1, *pL2 = l2;
        ListNode *result = new ListNode(0), *pResult = result;
        int value = 0;
        while(pL1 || pL2)
        {
            value /= 10;
            if(pL1)
            {
                value += pL1->val;
                pL1 = pL1->next;
            }
            if(pL2)
            {
                value += pL2->val;
                pL2 = pL2->next;
            }   
           
            pResult->next = new ListNode(value % 10);
            pResult = pResult->next;
        }
        if(value / 10 == 1 )
            pResult->next = new ListNode(1);
        return result->next;
    }
};

/**************reference*****************/
ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    ListNode preHead(0), *p = &preHead;
    int extra = 0;
    while (l1 || l2 || extra) {
        int sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + extra;
        extra = sum / 10;
        p->next = new ListNode(sum % 10);
        p = p->next;
        l1 = l1 ? l1->next : l1;
        l2 = l2 ? l2->next : l2;
    }
    return preHead.next;
}