/*@Description: Clone Graph
Clone an undirected graph. Each node in the graph contains a label and a list of its neighbors.
OJ's undirected graph serialization:
Nodes are labeled uniquely.
We use # as a separator for each node, and , as a separator for node label and each neighbor of the node.
As an example, consider the serialized graph {0,1,2#1,2#2,2}.
The graph has a total of three nodes, and therefore contains three parts as separated by #.
First node is labeled as 0. Connect node 0 to both nodes 1 and 2.
Second node is labeled as 1. Connect node 1 to node 2.
Third node is labeled as 2. Connect node 2 to node 2 (itself), thus forming a self-cycle.
Visually, the graph looks like the following:
       1
      / \
     /   \
    0 --- 2
         / \
         \_/
*/

//Definition for undirected graph.
struct UndirectedGraphNode 
{
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
};

/**广度优先遍历
创建一个hash表，用于将原图中的所有节点和新拷贝的节点一一对应，然后采用广度优先遍历的方法依次访问原图节点，
拷贝创建对应的新节点，并处理邻接关系
*/
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if(!node)   return NULL;
        unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> mp;
        UndirectedGraphNode* copy = new UndirectedGraphNode(node->label);
        mp[node] = copy;
        queue<UndirectedGraphNode*> toVisit;
        toVisit.push(node);
        while(!toVisit.empty())
        {
            UndirectedGraphNode* cur = toVisit.front();
            toVisit.pop();
            for(UndirectedGraphNode* neigh : cur->neighbors)
            {
                if(mp.find(neigh) == mp.end())  //如果原图节点的对应结点不存在则创建
                {
                    UndirectedGraphNode* copy_neigh = new UndirectedGraphNode(neigh->label);
                    mp[neigh] = copy_neigh;
                    toVisit.push(neigh);
                }
                mp[cur]->neighbors.push_back(mp[neigh]);    //存储新节点的相邻结点
            }
        }
        return copy;
    }
};

//深度优先遍历（递归法）
class Solution {
private:
    unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> mp;
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if(!node)   return NULL;
        if(mp.find(node) == mp.end())
        {
            mp[node] = new UndirectedGraphNode(node->label);     
            for(UndirectedGraphNode* neigh : node->neighbors)
            {
                mp[node]->neighbors.push_back(cloneGraph(neigh));
            }
        }
        return mp[node];
    }
};

