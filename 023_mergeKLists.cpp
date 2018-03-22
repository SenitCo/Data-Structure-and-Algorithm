/*@Description: Merge k Sorted Lists
Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

/*与合并两个有序列表的思想一致，每次比较 K 个节点，取其最小值；在遍历过程中，
若有列表已到达末尾节点，则将该列表从vector中移除
*/

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty())
            return NULL;
        vector<ListNode*> pl;
        for (auto node : lists)
            pl.push_back(node);
        ListNode* start = new ListNode(0);
        ListNode* pNode = start;
        int value = INT_MAX, index = 0;
        while (true)
        {
            for (auto iter = pl.begin(); iter != pl.end();)
            {
                if (!(*iter))
                {
                    iter = pl.erase(iter);	//注意erase()可能会造成后面的迭代器失效
                }
                else
                    iter++;
            }
            if (pl.empty())
                break;
            value = INT_MAX;
            index = 0;
            for (int i = 0; i < pl.size(); i++)
            {
                if (pl[i]->val < value)
                {
                    value = pl[i]->val;
                    index = i;
                }
            }
            pNode->next = pl[index];
            pl[index] = pl[index]->next;
            pNode = pNode->next;
        }
        return start->next;
    }
};

/*采用优先队列的方法*/
struct cmp
{
    bool operator()(ListNode* l1, ListNode* l2)
    {
        return l1->val > l2->val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty())
            return NULL;     
        ListNode* start = new ListNode(0);
        ListNode* pNode = start;
        priority_queue<ListNode*, vector<ListNode*>, cmp> pql;
        for (auto node : lists)
            if(node)			//注意此处要判断节点(链表)是否为空
                pql.push(node);
        while(!pql.empty())
        {
            pNode->next = pql.top();
            pql.pop();
            pNode = pNode->next;
            if(pNode->next != NULL)
                pql.push(pNode->next);
        }     
        return start->next;
    }
};

/*递归解法，将有序列表两两合并*/
class Solution {
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        if(lists.empty()){
            return nullptr;
        }
        while(lists.size() > 1){
            lists.push_back(mergeTwoLists(lists[0], lists[1]));
            lists.erase(lists.begin());
            lists.erase(lists.begin());
        }
        return lists.front();
    }
    
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        if(l1 == nullptr){
            return l2;
        }
        if(l2 == nullptr){
            return l1;
        }
        if(l1->val <= l2->val)
        {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        }
        else
        {
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }
    }
};