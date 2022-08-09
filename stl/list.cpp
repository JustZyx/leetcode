//熟悉STL双向链表操作
#include <iostream>
#include <list>
using namespace std;

std::ostream& operator<<(std::ostream& ostr, const std::list<int>& list) {
  for (auto& i : list) {
    ostr << " " << i;
  }
  return ostr;
}

int main() {
  list<int> l = {1, 2, 3, 4, 5};
  
  //头部插入新元素
  l.push_front(0);
  cout << "l: " << l << endl;

  //尾部删除元素
  l.pop_back();
  cout << "l: " << l << endl;

  //指针自增
  auto it = l.begin();
  advance(it, 2);

  //移动指定元素到指定位置
  l.splice(l.begin(), l, it);
  cout << "l: " << l << endl;
  
  return 0;
}