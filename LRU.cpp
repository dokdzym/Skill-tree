#include<iostream>
#include<vector>
#include<list>
#include<unordered_map>
using namespace std;
class LRU {
private:
	struct Node {
		int key;
		int value;
		Node(int k, int v):key(k), value(v){}
	};
	int capacity;//LRU缓存的最大空间
	list<Node> cacheList;//链表实现O（1）的插入、删除
	unordered_map<int, list<Node>::iterator> cacheMap;//hash表快速找到key对应的value
public:
	LRU(int c):capacity(c){}
	//get访问缓存时，提到list头部
	int get(int key) {
		if (cacheMap.find(key) != cacheMap.end()) //缺页中断
			return -1;
		//key对应的Node应该移动到list的最前端
		//关于splice的这次调用，作用是把一个容器（参数2）的迭代器指向的元素（参数3）移动到调用容器的指定位置（参数1）
		cacheList.splice(cacheList.begin(), cacheList, cacheMap[key]);
		cacheMap[key] = cacheList.begin();
		return cacheMap[key] -> value;
	}

	//set允许改变已有key的value
	int set(int key, int value) {
		//如果想set的K-V不在链表内，
		if (cacheMap.find(key) == cacheMap.end()) {
			if (cacheList.size() == capacity) {//缓存满,删除最远使用的Node
				cacheMap.erase(cacheList.back().key);
				cacheList.pop_back();
			}
			cacheList.push_front(Node(key, value));
			cacheMap[key] = cacheList.begin();
		}
		//在链表内,把尾部移到头部
		else {
			cacheMap[key]->value = value;
			cacheList.splice(cacheList.begin(), cacheList, cacheMap[key]);
			cacheMap[key] = cacheList.begin();
		}
	}
};
