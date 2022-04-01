#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

//1->2->3->4
//2->1->4->3
//反转链表
ListNode *reverse(ListNode *head, int k) {
  ListNode *pre = nullptr;
  for (int i = 0; i < k; i++) {
    ListNode *next = head->next;
    head->next = pre;
    pre = head;
    head = next;
  }
  return pre;
}

// k个一组反转链表
// return 反转后的头节点
ListNode *reverseKGroup(ListNode *head, int k) {
  //头节点为空,则返回空
  if (!head) return head;

  //找寻第二个k段起点
  ListNode *nextHead = head;
  for (int i = 0; i < k; i++) {
    if (!nextHead)
      return head;  //如果长度不足k,则停止寻找下一个k段起点,保持不变
    nextHead = nextHead->next;
  }

  ListNode *newhead = reverse(head, k);
  head->next = reverseKGroup(nextHead, k);
  return newhead;
}

//通过vector构造链表
ListNode *getListByVector(vector<int> nums) {
  ListNode *pre = new ListNode(0);
  ListNode *sential = pre;
  for (auto num : nums) {
    pre->next = new ListNode(num);
    pre = pre->next;
  }
  return sential->next;
}

//打印链表
void printList(ListNode *head) {
  while (head) {
    cout << head->val << " ";
    head = head->next;
  }
  cout << endl;
}

int main(int argc, char *argv[]) {
  vector<int> nums = {1, 2, 3, 4, 5};
  ListNode *head = getListByVector(nums);
  printList(head);
  cout << endl;

  int k = 2;
  if (argc > 1) {
    k = atoi(argv[1]);
  }
  ListNode *newHead = reverseKGroup(head, k);
  printList(newHead);
}