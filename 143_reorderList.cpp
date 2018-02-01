/*@Description: Reorder List
Given a singly linked list L: L0→L1→…→Ln-1→Ln,
reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…
You must do this in-place without altering the nodes' values.
For example, Given {1,2,3,4}, reorder it to {1,4,2,3}.
*/

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

/**
首先遍历一次得到整个链表的长度，然后取其一半，将链表分为前后两部分，从前半部分的尾部开始，
插入后半部分的首部元素，然后前半部分的元素向前遍历，后半部分的元素向后遍历，逐个插入。前半
部分的元素向前遍历实际上是通过从头指针向后移动步长step实现的，步长逐次递减
*/
class Solution {
public:
    void reorderList(ListNode* head) {
        if(!head || !head->next)
            return;
        int length = 0;
        for(ListNode* node = head; node; node = node->next)
            length++;
        int step = length / 2;
        int flag = length % 2;
        ListNode *front, *back, *tail, *temp;
        tail = head;
        for(int i = 0; i < step; i++)
            tail = tail->next;
        back = tail->next;
        tail->next = NULL;	//将中间节点的后继指针置为NULL
        if(flag)	//区分链表长度为奇偶的情况
            step -= 1;
        else
            step -= 2;
        while(back)
        {
            front = head;
            for(int i = 0; i < step; i++)
                front = front->next;
            temp = back->next;
            back->next = front->next;
            front->next = back;
            back = temp;
            step--;
        }
    }
};

/**
分三步：
(1)找到链表的中点位置middle=(len-1)/2
(2)将后半部分（middle之后的元素）链表逆转
(3)同时遍历两部分链表元素，依次将后半部分元素插入到前半部分的相应位置
*/
class Solution {
public:
    void reorderList(ListNode* head) {
        if(!head || !head->next)
            return;
        ListNode *p1, *p2;
        p1 = p2 = head;
        //Find the middle of the list, 1->2->3->4->5->6, middle point to 3
        while(p2->next && p2->next->next)
        {
            p1 = p1->next;
            p2 = p2->next->next;
        }
        //Reverse the half after middle  1->2->3->4->5->6 to 1->2->3->6->5->4
        ListNode *middle = p1, *prev = p1->next, *cur;
        while(prev->next)
        {
            cur = prev->next;
            prev->next = cur->next;
            cur->next = middle->next;
            middle->next = cur;
        }
        //Start reorder one by one  1->2->3->6->5->4 to 1->6->2->5->3->4
        p1 = head;
        p2 = middle->next;
        while(p1 != middle)
        {
            middle->next = p2->next;
            p2->next = p1->next;
            p1->next = p2;
            p1 = p2->next;
            p2 = middle->next;
        }
    }
};