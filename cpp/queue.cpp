#include <queue>
#include <vector>
#include <iostream>
using namespace std;

int main()
{
  // 执行 pq.top() 之前必须得先判断 pq.size() > 0
  // priority_queue<int, vector<int>, greater<int>> pq;
  // cout << pq.top() << endl;

  queue<int> q;
  q.push(0);
  q.push(1);
  q.push(2);

  while (!q.empty()) {
    cout << q.back() << endl;
    cout << q.front() << endl;
    q.pop();
  }

  return 0;
}