//后来的插入链表头部
//如果新增的key已经存在则更新完value以后移动到头部
//如果不存在
//已经满了,删除末尾元素
//未满, 不用动
//插入头部,更新哈希

//实现如下接口

//插入到链表头部: emplace_front
//删除链表尾部: pop_back
//删除指定节点: splice

#include <list>
#include <unordered_map>
#include <utility>
#include <iostream>
using namespace std;

class LRUCache {
  int cap;
  list<pair<int, int>> m_list;
  unordered_map<int, list<pair<int, int>>::iterator> u_map;

 public:
  LRUCache(int capacity);
  int get(int key);
  void put(int key, int value);
};

LRUCache::LRUCache(int capacity) { this->cap = capacity; }

int LRUCache::get(int key) {
  auto iter = u_map.find(key);

  //找不到返回-1
  if (iter == u_map.end()) return -1;

  //能找到移到链表头部
  m_list.splice(m_list.begin(), m_list, iter->second);
  return iter->second->second;
}

void LRUCache::put(int key, int value) {
  auto iter = u_map.find(key);
  if (iter != u_map.end()) {
    iter->second->second = value;
    m_list.splice(m_list.begin(), m_list, iter->second);
    return;
  }

  //找不到
  if (u_map.size() >= cap) {
    //已经满了删除并更新哈希
    auto backIter = m_list.back();
    m_list.pop_back();
    u_map.erase(backIter.first);
  }

  //新增
  m_list.emplace_front(key, value);
  u_map[key] = m_list.begin();
}

int main() {
    auto lRUCache = new LRUCache(2);
    lRUCache->put(1, 1); // 缓存是 {1=1}
    lRUCache->put(2, 2); // 缓存是 {1=1, 2=2}
    cout << lRUCache->get(1) << endl;    // 返回 1
    lRUCache->put(3, 3); // 该操作会使得关键字 2 作废，缓存是 {1=1, 3=3}
    cout << lRUCache->get(2) << endl;;    // 返回 -1 (未找到)
    lRUCache->put(4, 4); // 该操作会使得关键字 1 作废，缓存是 {4=4, 3=3}
    cout << lRUCache->get(1) << endl;    // 返回 -1 (未找到)
    cout << lRUCache->get(3) << endl;    // 返回 3
    cout << lRUCache->get(4) << endl;    // 返回 4
}