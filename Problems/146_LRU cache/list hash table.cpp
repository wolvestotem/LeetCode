#include"../leetcode.h"

class LRUCache {
    unordered_map<int,list<pair<int,int>>::iterator> map;
    list<pair<int,int>> order;
    int capacity_;
public:
    LRUCache(int capacity):capacity_(capacity) {
        
    }
    
    int get(int key) {
        if(!map.count(key))
            return -1;
        else{
            list<pair<int,int>>::iterator it;
            it = map[key];
            pair<int,int> kv = *it;
            order.erase(it);
            order.push_front(kv);
            map[key]=order.begin();
            return kv.second;
        }
    }
    
    void put(int key, int value) {
        if(map.count(key)){
            list<pair<int,int>>::iterator it;
            it = map[key];
            pair<int,int> kv = *it;
            kv.second = value;
            order.erase(it);
            order.push_front(kv);
            map[key] = order.begin();
        }
        else{
            if(order.size()==capacity_){
                map.erase(order.back().first);
                order.pop_back();
                order.push_front(make_pair(key,value));
                map[key] = order.begin();
            }
            else{
                order.push_front(make_pair(key,value));
                map[key] = order.begin();
            }
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */