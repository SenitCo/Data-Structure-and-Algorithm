/*@Description: Reverse Linked List II
Reverse a linked list from position m to n. Do it in-place and in one-pass.

For example:
Given 1->2->3->4->5->NULL, m = 2 and n = 4,
return 1->4->3->2->5->NULL.

Note:
Given m, n satisfy the following condition: 1 ≤ m ≤ n ≤ length of list.
*/

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
/**
借助两个指针，cur指向链表中第 m-1 个元素，nex指向原链表中第 m 个元素，然后将nex后面的元素逐个插入到cur后面，
直至第 n 个元素
*/
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode* start = new ListNode(0);
        ListNode* cur, *nex, *tmp;
        start->next = head;
        cur = start;
        int i = 0;
        for(; i < m - 1; i++)
        {
            cur = cur->next;
        }
        nex = cur->next;
        for(; i < n - 1 && nex->next; i++)	//i初值为 m-1，后续插入操作次数为 n-m
        {
            tmp = cur->next;				//暂时存储cur后面的元素
            cur->next = nex->next;			//将nex后面的元素插入到cur后
            nex->next = nex->next->next;	//取出nex的下一个元素后，nex的下一个元素变成更后面的元素
            cur->next->next = tmp;			//将插入到cur的元素与之前暂存的元素链接起来
        }
        return start->next;
    }
};

/**
思路和上述方法一样，只是借助三个指针，pre指向链表中的第 m-1 个元素，begin指向第一个未逆转的元素，
then指向begin的下一个元素，即即将插入到pre后面的元素，then = begin->next，依次将begin后面的元素
插入到pre后面，并保证所有元素能连接成串
*/
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode* start = new ListNode(0);  
        start->next = head;
        ListNode *pre = start;
        for(int i = 0; i < m - 1; i++)
            pre = pre->next;
        ListNode* begin = pre->next;
        ListNode* then = begin->next;
       
        for(int i = 0; i < n - m; i++)
        {
            begin->next = then->next;
            then->next = pre->next;
            pre->next = then;
            then = begin->next;
        }
        return start->next;
    }
};