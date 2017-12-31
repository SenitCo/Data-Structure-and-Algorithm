/*@Description: Rotate List
Given a list, rotate the list to the right by k places, where k is non-negative.
Example:
Given 1->2->3->4->5->NULL and k = 2,
return 4->5->1->2->3->NULL.
*/

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

/**
此处没必要利用快慢指针来定位到倒数第k个位置，因为k值可能大于链表结点数，所以必须先遍历一次获取链表的长度，
然后取模相减，得到需要移动的步长(len - k % len)，在第一次遍历至链表尾时，可直接将链表首尾相连，然后继续移动
(len - k % len)个步长，记录首结点指针start=tail->next，并使tail=NULL，解除环形
*/
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head)
            return head;
        int len = 1;
        ListNode *start = head, *tail = head;
        while(tail->next)
        {
            tail = tail->next;
            len++;
        }
        tail->next = head;  //首尾相连
        k = k % len;    //k值可大于结点数
        if(k > 0)
        {
            for(int i = 0; i < len - k; i++)
                tail = tail->next;
        }
        start = tail->next;
        tail->next = NULL;  //解除环形
        return start;
    }
};