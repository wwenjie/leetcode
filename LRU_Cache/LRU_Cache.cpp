#include<iostream>
#include<stdio.h>
#include<vector>
#include<unordered_map>

using namespace std;

/*
class Item;
class LRUCache;
如果把LRUCache类定义放main()下面，然后在main()前面放LRUCache类声明，那LRUCache类声明之前比如main()里面，不能实例化这个LRUCache类
类的前向声明，是利用了编译器特性，编译器编译时只要知道各个元素的名称和大小即可。
但是声明之后，定义之前，LRUCache类时不完全的类型（incomplete type），编译器只知道这是个类型，但不知道这个类的性质（比如成员和方法），所以不能通过这个前向声明的类的指针或对象取操作自己的成员，不能用来实例化。
参考：https://blog.csdn.net/leigelaile1/article/details/80622429
*/

/*
	构造函数，形参和成员变量重名，会有问题
*/

class Item{
public:
    Item(int k, int v): k(k), v(v){}
    Item(){}
    Item* prev;
    Item* next;
    int k;
    int v;
};

class LRUCache {
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
		cout<<"11--->"<<capacity<<endl;
		//cout<<"22--->"<<this->capacity<<endl;

    }

    int get(int key) {
        if(umap.find(key) == umap.end())
            return -1;
        Item* it = umap[key];
        del_queue(it);
        push_queue(it);
        return it->v;
    }

    void put(int key, int value) {
        Item* it;
        if(umap.find(key) != umap.end()){
            //已存在
            it = umap[key];
            del_queue(it);
            it->v = value;
        }
        else {
            //不存在
            if (umap.size() + 1 > capacity){
                // 满cap
                it = pop_queue();
                umap.erase(it->k);
                it->k = key;
                it->v = value;
                it->prev = nullptr;
                it->next = nullptr;
            }
            else{
                // 不满cap
                it = new Item(key, value);
            }
        }
        umap[key] = it;
        push_queue(it);
    }
	int get_cap(){
		return capacity;	
	}
private:
    int capacity;
    Item* queue_head = nullptr;
    Item* queue_tail = nullptr;
    unordered_map<int, Item*> umap;
    void push_queue(Item* it){
        if (queue_head == nullptr){
            queue_head = it;
            queue_tail = it;
        }
        else{
            queue_tail->next = it;
			it->prev = queue_tail;
            queue_tail = it;
        }
    }
    Item* pop_queue(){
        if (queue_head == nullptr)
            return nullptr;
        Item* it = queue_head;
		Item* next = it->next;
        queue_head = next;
		if(next)
			next->prev = nullptr;
        return it;
    }
    void del_queue(Item* it){
        Item* prev = it->prev;
        Item* next = it->next;
        if (queue_head == it)
            queue_head = next;
        if (queue_tail == it)
            queue_tail = prev;
        if (prev != nullptr)
            prev->next = next;
        if (next != nullptr)
            next->prev = prev;
        it->prev = nullptr;
        it->next = nullptr;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */



void check1(){
	LRUCache* lRUCache = new LRUCache(2);
	int ans;
	lRUCache->put(1, 1); // 缓存是 {1=1}
	lRUCache->put(2, 2); // 缓存是 {1=1, 2=2}
	ans = lRUCache->get(1);    // 返回 1
	//cout<<ans<<endl;
	lRUCache->put(3, 3); // 该操作会使得关键字 2 作废，缓存是 {1=1, 3=3}
	ans = lRUCache->get(2);    // 返回 -1 (未找到)
	//cout<<ans<<endl;
	lRUCache->put(4, 4); // 该操作会使得关键字 1 作废，缓存是 {4=4, 3=3}
	ans = lRUCache->get(1);    // 返回 -1 (未找到)
	//cout<<ans<<endl;
	ans = lRUCache->get(3);    // 返回 3
	//cout<<ans<<endl;
	ans = lRUCache->get(4);    // 返回 4
	//cout<<ans<<endl;
	Item* it = new Item();
	cout<<int(it->k)<<endl;
	printf("%p\n", it->prev);
}

void check2(){
	LRUCache* cache = new LRUCache(2);
	int ans;
	ans = cache->get(2);
	cout<<"1-->"<<ans<<endl;
	cache->put(2, 6);
	//{(2,6)}
	ans = cache->get(1);
	cout<<"2-->"<<ans<<endl;
	cache->put(1, 5);
	//{(2,6),(1,5)}
	cout<<"3-->"<<endl;
	cache->put(1, 2);
	
	cout<<"4-->"<<endl;
	ans = cache->get(1);
	cout<<ans<<endl;
	ans = cache->get(2);
	cout<<ans<<endl;
}

int main() {
	check2();
	return 0;
}
