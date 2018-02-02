/*@Description: Copy List with Random Pointer
A linked list is given such that each node contains an additional random pointer which could point to 
any node in the list or null. Return a deep copy of the list.
*/


//Definition for singly-linked list with a random pointer.
struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

/**
比较直接的思路是，先按照复制一个正常链表的方式复制，复制的时候把复制的结点做一个HashMap，以旧结点为key，
新节点为value。这么做的目的是为了第二遍扫描的时候我们按照这个哈希表把结点的随机指针接上。总共要进行两次
扫描，时间复杂度是O(2*n)=O(n)。空间上需要一个哈希表来做结点的映射，空间复杂度也是O(n)。HashMap的作用是在
连接随机指针时，能够在原链表和新链表之间形成一一对应关系。
*/
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if(head == NULL)    return NULL;
        unordered_map<RandomListNode*, RandomListNode*> mp;
        RandomListNode *newHead = new RandomListNode(head->label);
        mp[head] = newHead;
        RandomListNode *node = head->next, *prev = newHead;
        while(node)
        {
            RandomListNode *newNode = new RandomListNode(node->label);
            prev->next = newNode;
            mp[node] = newNode;
            prev = newNode;
            node = node->next;
        }
        
        node = head;
        RandomListNode *copyNode = newHead;
        while(node)
        {
            copyNode->random = mp[node->random];
            copyNode = copyNode->next;
            node = node->next;
        }
        return newHead;
    }
};

/**
想避免使用额外空间，只能通过利用链表原来的数据结构来存储结点。基本思路是：对链表进行三次扫描，第一次扫描对每个结点
进行复制，然后把复制出来的新节点接在原结点的next，也就是让链表变成一个重复链表，新旧更替；第二次扫描中把旧结点的
随机指针（下一个的结点）赋给新节点的随机指针，因为新结点都跟在旧结点的下一个，所以赋值比较简单，就是node->next->random
 = node->random->next，其中node->next是新结点.最后一次扫描把链表拆成两个，第一个还原原链表，而第二个就是要求的复制链表。
因为现在链表是旧新更替，只要把每隔两个结点分别相连，对链表进行分割即可。这个方法总共进行三次线性扫描，时间复杂度是O(n)。
而这里并不需要额外空间，空间复杂度是O(1)。比起上面的方法，这里多做一次线性扫描，但是不需要额外空间。
*/
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if(head == NULL)    return NULL;
        RandomListNode *node = head;
        while(node)
        {
            RandomListNode *newNode = new RandomListNode(node->label);
            newNode->next = node->next;
            node->next = newNode;
            node = newNode->next;
        }
        
        node = head;
        while(node)
        {
            if(node->random)
                node->next->random = node->random->next;
            node = node->next->next;
        }
        
        RandomListNode *newHead = head->next, *newNode;
        node = head;
        while(node)
        {
            newNode = node->next;
            node->next = newNode->next;
            if(newNode->next)
                newNode->next = newNode->next->next;
            node = node->next;
            
        }
        return newHead;
    }
};