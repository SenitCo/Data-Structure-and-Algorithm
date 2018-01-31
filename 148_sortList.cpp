/*@Descripton: Sort List
Sort a linked list in O(n log n) time using constant space complexity.
*/

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

/**
归并排序的递归解法，不符合要求，空间复杂度为O(logn)，自顶向下执行
*/
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if(head == NULL || head->next == NULL)
            return head;
        ListNode *prev = NULL, *slow, *fast;
        slow = fast = head;
        while(fast && fast->next)
        {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;	//快指针每次走两步，最终慢指针指向链表中间
        }
        prev->next = NULL;
        ListNode* l1 = sortList(head);
        ListNode* l2 = sortList(slow);
        return mergeList(l1, l2);
    }
private:
    ListNode* mergeList(ListNode* l1, ListNode* l2)
    {
        ListNode* node = new ListNode(0);
        ListNode* p = node;
        while(l1 && l2)
        {
            if(l1->val < l2->val)
            {
                p->next = l1;
                l1 = l1->next;
            }
            else
            {
                p->next = l2;
                l2 = l2->next;
            }
            p = p->next;
        }
        if(l1)
            p->next = l1;
        if(l2)
            p->next = l2;
        return node->next;
    }
};

/**
归并排序的迭代解法，空间复杂度为O(1)，自底向上执行
*/
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if(head == NULL || head->next == NULL)
            return head;
        ListNode *cur = head;
        int length = 0;
        while(cur)
        {
            length++;
            cur = cur->next;
        }
        ListNode *start = new ListNode(0);
        start->next = head;
        ListNode *left, *right, *tail;
        for(int step = 1; step < length; step <<= 1)
        {
            cur = start->next;
            tail = start;
            while(cur)	//每次两两归并，得到一个有序序列
            {
                left = cur;
                right = split(left, step);
                cur = split(right, step);
                tail = merge(left, right, tail);
            }
        }
        return start->next;
    }
    
private:
	//将链表划分为两个链表，每个链表n个元素，并返回下一个链表的首部
    ListNode* split(ListNode* head, int n)
    {
        for(int i = 1; head && i < n; i++)
            head = head->next;
        if(!head)    return NULL;
        ListNode* second = head->next;
        head->next = NULL;  
        return second;
    }
    //合并两个链表，并返回合并后的链表的尾部，即下一个链表的首部
    ListNode* merge(ListNode* l1, ListNode* l2, ListNode* head)
    {
        ListNode* cur = head;
        while(l1 && l2)
        {
            if(l1->val < l2->val)
            {
                cur->next = l1;
                l1 = l1->next;
            }
            else
            {
                cur->next = l2;
                l2 = l2->next;
            }
            cur = cur->next;
        }
        cur->next = l1 ? l1 : l2;
        while(cur->next)  cur = cur->next;
        return cur;
    }
   
};