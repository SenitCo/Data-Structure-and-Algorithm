/*@Description: LRU Cache
Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get and put.
get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
put(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity, it should 
invalidate the least recently used item before inserting a new item.
Follow up: Could you do both operations in O(1) time complexity?
Example: LRUCache cache = new LRUCache(2);
cache.put(1, 1);
cache.put(2, 2);
cache.get(1);       // returns 1
cache.put(3, 3);    // evicts key 2
cache.get(2);       // returns -1 (not found)
cache.put(4, 4);    // evicts key 1
cache.get(1);       // returns -1 (not found)
cache.get(3);       // returns 3
cache.get(4);       // returns 4
*/

/**
借助一个双向链表和hash表实现，链表用于存储<key, value>对，hash表的key为链表的key值，value为链表的迭代器
（可自己实现一个简单的双向链表，在使用hash表的时候不会涉及到两级迭代器）
*/
class LRUCache {
public:
    LRUCache(int capacity) {
        _capacity = capacity;
    }
    
    int get(int key) {
        auto iter = cache.find(key);
        if(iter == cache.end()) return -1;
        touch(iter);	//将刚访问的元素移至链表头
        return iter->second->second;
    }
    
    void put(int key, int value) {
        auto iter = cache.find(key);
        if(iter != cache.end())
        {
            iter->second->second = value;	 //改变结点value值，并将结点移至链表头
            touch(iter);
        }
        else
        {
            if(cache.size() == _capacity)	//达到容量则删除链表尾的结点并在hash表中移除对应元素
            {
                cache.erase(kv.back().first);
                kv.pop_back();
            }
            kv.push_front(make_pair(key, value));	//链表头插入新结点
        }
        cache[key] = kv.begin();	//将最近一次访问的结点元素（链表头）和hash表中的对应key配对
    }
private:
    typedef list<pair<int, int>> kvList;
    typedef unordered_map<int, kvList::iterator> kListMap;
    kvList kv;
    kListMap cache;
    int _capacity;
    //将已在hash表中的元素（结点）移至链表头
    void touch(kListMap::iterator iter)
    {
        kvList::iterator node = iter->second;
        kv.erase(node);
        kv.push_front(*node);
        iter->second = kv.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */