/*@Description: Insertion Sort List
Sort a linked list using insertion sort.
*/

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

/**
单链表的直接插入排序，每次将一个元素插入到排好序的序列中
*/
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if(head == NULL || head->next == NULL)
            return head;
        ListNode *start = new ListNode(0);
        ListNode *cur = head, *pre = start, *next = NULL;
        while(cur)
        {
            next = cur->next;
            while(pre->next && pre->next->val < cur->val)
                pre = pre->next;
            cur->next = pre->next;
            pre->next = cur;
            pre = start;
            cur = next;
        }
        return start->next;
    }
};

/**
单链表的选择排序，每次搜索无排序序列中的最小元素，将其加入到已排序序列的末尾，
并使其下一个元素指向未排序序列
*/
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if(head == NULL || head->next == NULL)
            return head;
        ListNode *start = new ListNode(0);
        start->next = head;
        ListNode *cur, *node, *minNode, *minPre, *preNode;
        for(cur = start; cur; cur = cur->next)
        {
            long long minVal = LLONG_MAX;
            preNode = cur;
            for(node = cur->next; node; node = node->next)
            {
                if(node->val < minVal)
                {
                    minVal = node->val;
                    minNode = node;
                    minPre = preNode;
                }
                preNode = node;
            }
            if(minPre != cur)
            {    
                ListNode *temp = cur->next;
                cur->next = minNode;
                minPre->next = minNode->next;
                minNode->next = temp;
            }
        }
        return start->next;
    }
};