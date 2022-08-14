/**
请你设计并实现一个满足 LRU (最近最少使用) 缓存 约束的数据结构。 

 实现 LRUCache 类： 

 LRUCache(int capacity) 以 正整数 作为容量 capacity 初始化 LRU 缓存 
 int get(int key) 如果关键字 key 存在于缓存中，则返回关键字的值，否则返回 -1 。 
 void put(int key, int value) 如果关键字 key 已经存在，则变更其数据值 value ；如果不存在，则向缓存中插入该组 key-
value 。如果插入操作导致关键字数量超过 capacity ，则应该 逐出 最久未使用的关键字。 

 函数 get 和 put 必须以 O(1) 的平均时间复杂度运行。
 示例： 

输入
["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
[[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
输出
[null, null, null, 1, null, -1, null, -1, 3, 4]

解释
LRUCache lRUCache = new LRUCache(2);
lRUCache.put(1, 1); // 缓存是 {1=1}
lRUCache.put(2, 2); // 缓存是 {1=1, 2=2}
lRUCache.get(1);    // 返回 1
lRUCache.put(3, 3); // 该操作会使得关键字 2 作废，缓存是 {1=1, 3=3}
lRUCache.get(2);    // 返回 -1 (未找到)
lRUCache.put(4, 4); // 该操作会使得关键字 1 作废，缓存是 {4=4, 3=3}
lRUCache.get(1);    // 返回 -1 (未找到)
lRUCache.get(3);    // 返回 3
lRUCache.get(4);    // 返回 4

 提示：
 1 <= capacity <= 3000 
 0 <= key <= 10000 
 0 <= value <= 10⁵ 
 最多调用 2 * 10⁵ 次 get 和 put 
 
 Related Topics 设计 哈希表 链表 双向链表 👍 2335 👎 0

*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <map>
#include <stack>
#include <set>
using namespace std;
//思考
//get O(1) ：用map，需要一个双向链表用来LRU
//put O（1）：get用map，put往map里加，且需要一个双向链表用来LRU
//leetcode submit region begin(Prohibit modification and deletion)
struct douList{
    int value;
    douList * pre;
    douList * next;

    douList(){}
    douList(int value){
        this->value=value;
    }
};
class LRUCache {
public:
    int capacity;
    int size;
//    map<int, int> myMap;//直接存储值，则在get时找到对应的listNode复杂度为O n
    map<int, douList *> myMap;//直接存储值，则在get时找到对应的listNode复杂度为O n
    douList * first;
    douList * last;

    LRUCache(){}

    LRUCache(int capacity) {
        this->size=0;
        this->capacity=capacity;
        this->last=new douList(-1);
        this->first=new douList(-1);
        last->pre=first;
        last->next=NULL;
        first->pre=NULL;
        first->next=last;
    }
    
    int get(int key) {
        if (myMap.count(key)){
            douList * getNode = myMap[key];// myMap.find 返回的时迭代器
            getNode->pre->next=getNode->next;
            getNode->next->pre=getNode->pre;
            last->pre->next=getNode;
            getNode->pre=last->pre;
            getNode->next=last;
            return getNode->value;
        }

        return -1;
    }
    
    void put(int key, int value) {
        douList * newNode = new douList(value);
        myMap[key]=newNode;
        this->size++;

        if (this->size > this->capacity){
            myMap.erase(key);
            first->next=first->next->next;
            first->next->pre=first;
            this->size--;
        }

        last->pre->next=newNode;
        newNode->next=last;
        newNode->pre=last->pre;
        last->pre=newNode;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
//leetcode submit region end(Prohibit modification and deletion)
