/*
 * @Date: 2021-11-29 11:04:02
 * @LastEditors: kafier
 * @LastEditTime: 2021-11-29 11:51:54
 */

#include <unordered_map>
using namespace std;

// 哈希表 + 双向链表
/**
 * @description: 
 * put{key, value} 这很明显需要通过哈希表实现
 * 但是要实现在超出容量的收， 将删除最久未使用的数据值， 从而为新的数据值留出空间
 * 并且还要实现get的时候更新到头节点
 *  unordered_map不应该存储的是<int, dlinkednode>
 * @param {*}
 * @return {*}
 */
struct DlinkedNode{
    int key, value;
    DlinkedNode* prev;
    DlinkedNode* next;
    DlinkedNode():key(0), value(0), prev(nullptr), next(nullptr){}
    DlinkedNode(int _key, int _value):key(_key), value(_value), prev(nullptr),next(nullptr){}

};

class LRUCache {
private:
    unordered_map<int, DlinkedNode*> cache;
    DlinkedNode* head;
    DlinkedNode* tail;
    int size;
    int capacity;

public:
    LRUCache(int _capacity):capacity(_capacity) ,size(0){
        head = new DlinkedNode();
        tail = new DlinkedNode();
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if(!cache.count(key)){
            return -1;
        }
        DlinkedNode* node = cache[key];
        moveTohead(node);
        return node->value;
    }
    
    void put(int key, int value) {
        if(!cache.count(key))
        {
            DlinkedNode* node = new DlinkedNode(key, value);
            cache[key] = node;
            addTohead(node);
            ++size;
            if(size > capacity)
            {
                DlinkedNode* removed = removetail();
                cache.erase(removed->key);
                delete  removed;
                --size;
            }
        }
        else{
            DlinkedNode* node = cache[key];
            node->value = value;
            moveTohead(node);
        }
    }

    void addTohead(DlinkedNode* node){
        node->prev = head;
        node->next = head->next;
        head->next->prev = node;
        head->next = node;
    }

    void removeNode(DlinkedNode* node){
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void moveTohead(DlinkedNode* node){
        removeNode(node);
        addTohead(node);
    }
    DlinkedNode* removetail()
    {
        DlinkedNode* node = tail->prev;
        removeNode(node);
        return node;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */