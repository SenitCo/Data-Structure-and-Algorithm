/*@Description: Reverse Linked List
Reverse a singly linked list.
*/

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

/**迭代法：
借助三个指针，头指针start的下一个元素为逆转后的第一个元素，first指向第一个未逆转的元素，second指向first
的下一个元素，即即将插入到start后面的元素，second = first->next，依次将first后面的元素插入到start后面，
并保证所有元素能连接成串
*/
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(!head)
            return NULL;
        ListNode* start = new ListNode(0);
        start->next = head;
        ListNode *first = head;
        ListNode *second = first->next;
        while(second)
        {
            first->next = second->next;
            second->next = start->next;
            start->next = second;
            second = first->next;
        }
        return start->next;
    }
};

/**
更简洁的迭代法
*/
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* start = NULL;
        while(head)
        {
            ListNode* next = head->next;
            head->next = start;
            start = head;
            head = next;
        }
        return start;
    }
};

/**
递归法
*/
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        return recursive(head, NULL);
    }
private:
    ListNode* recursive(ListNode* head, ListNode* start)
    {
        if(!head)   return start;
        ListNode* next = head->next;
        head->next = start;
        return recursive(next, head);
    }
};