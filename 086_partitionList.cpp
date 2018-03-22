/*@Description: Partition List
Given a linked list and a value x, partition it such that all nodes less than x come before nodes 
greater than or equal to x. You should preserve the original relative order of the nodes in each 
of the two partitions.
For example,
Given 1->4->3->2->5->2 and x = 3,
return 1->2->2->4->3->5.
*/


//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

/**
借助两个指针，less和greater，分别指向小于目标值的元素和大于等于目标值的元素，遍历一次，即可得到两个链表，
然后将其合并为一个
*/
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* less = new ListNode(0);
        ListNode* greater = new ListNode(0);
        ListNode *ptr1 = less, *ptr2 = greater, *pNode = head;
        while(pNode)
        {
            if(pNode->val < x)
            {
                ptr1->next = pNode;
                ptr1 = ptr1->next;
            }
            else
            {
                ptr2->next = pNode;
                ptr2 = ptr2->next;
            }
            pNode = pNode->next;
        }
        ptr1->next = greater->next;
        ptr2->next = NULL;
        return less->next;
    }
};