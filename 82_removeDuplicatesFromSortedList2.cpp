/*@Description: Remove Duplicates from Sorted List II
Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.
For example,
Given 1->2->3->3->4->4->5, return 1->2->5.
Given 1->1->1->2->3, return 2->3.
*/

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

/**
借助两个指针begin、end，分别指向重复元素区间（区间范围可为1）的前一个元素和后一个元素，如果不存在重复元素，
也就是区间范围为1，即begin->next->next = end，移动指针继续遍历；否则使begin->next = end，即去掉中间重复的元素
*/
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *pNode = new ListNode(0);
        pNode->next = head;
        ListNode *begin = pNode, *end = head;
        while(end)
        {
            while(end && end->val == begin->next->val)
                end = end->next;
            if(begin->next && begin->next->next != end)
            {
                begin->next = end;
                continue;
            }
            else
                begin = begin->next;
        }
        return pNode->next;
    }
};

/**
思路和上述方法一致，同样利用两个指针pre、cur，pre指向重复元素区间的前一个元素，cur指向区间内的最后一个元素，
比较cur指针相邻元素的值，如果不存在重复元素，则有pre->next = cur，移动pre指针继续遍历，即pre = pre->next；
否则去掉重复元素，使pre->next = cur->next
*/
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *pNode = new ListNode(0);
        pNode->next = head;
        ListNode *pre = pNode, *cur = head;
        while(cur)
        {
            while(cur->next && cur->val == cur->next->val)
                cur = cur->next;
            if(pre->next == cur)
                pre = pre->next;
            else
                pre->next = cur->next;
            cur = cur->next;
        }
        return pNode->next;
    }
};