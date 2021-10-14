#include <iostream>
#include <unordered_map>
using namespace std;

struct DlinkedNode
{
    DlinkedNode* prev;
    DlinkedNode* next;
    int key, value;
    DlinkedNode(): key(0), value(0), prev(nullptr), next(nullptr){}
    DlinkedNode(int _key, int _value):key(_key), value(_value), prev(nullptr), next(nullptr) {}
};

// use DlinkedNode , the Node near the tail must be delete first, and insert near the head;
class LRUCache {

private:
    // 哈希表
    unordered_map<int, DlinkedNode*> cache;
    DlinkedNode* head;
    DlinkedNode* tail;
    int size_;
    int capacity_;

public:
    LRUCache(int capacity) 
    :capacity_(capacity),
    size_(0)
    {
        //伪 首尾node
        DlinkedNode* head = new DlinkedNode();
        DlinkedNode* tail = new DlinkedNode();
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if(cache.count(key)){
            return -1;
        }
        DlinkedNode* node = cache[key];
        moveToHead(node);
        return  node->value;
    }   
    void put(int key, int value) {
        // 既然put了， 那就得放到前面
        // 如果这个元素本身不存在于cache
        if(!cache.count(key))
        {
            DlinkedNode* node = new DlinkedNode(key, value);
            cache[key] = node;
            addToHead(node);
            if(size_  >= capacity_)
            {
                DlinkedNode* ele = removeFromtail();
                cache.erase(ele->key);
                // delete and prevent the memory leak
                delete ele;
                --size_;
            }
        }
        else
        {
            // if the key exits;
            DlinkedNode* node = cache[key];
            node->value = value;
            moveToHead(node);
        }
    }


    // 必须考虑addToHead 和 moveToHead 的 区别
    // 如果是moveToHead, 则要把node给移除掉， 加入到Head去
    void addToHead(DlinkedNode* node)
    {
        // add to head, must notice the relation between node and head
        head->next->prev = node;
        node->next = head->next;
        head->next = node;
        node->prev = head;
    }
    void moveToHead(DlinkedNode* node)
    {
        removeNode(node);
        addToHead(node);
    }
    DlinkedNode* removeFromtail()
    {
        DlinkedNode* removeEle = tail->prev;
        removeNode(removeEle);
        return removeEle;
    }

    void removeNode(DlinkedNode* node)
    {
        node->prev->next = tail;
        tail->prev = node->prev;
    }
// 1. 时间机制  利用队列完成？ 还有链表
// 2. 映射机制  利用哈希
// 那么就是要结合哈希和链表写一个LRU 缓存机制
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */