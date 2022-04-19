#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct TreeNode
{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

// 二叉树的层序遍历
vector<vector<int>> levelOrder(TreeNode *root)
{
  vector<vector<int>> ret;
  //判空
  if (!root)
    return ret;
  
  queue<TreeNode *> q;
  q.push(root);
  while (!q.empty())
  {
    vector<int> layer;

    //遍历当前层
    int len = q.size();
    for (size_t i = 0; i < len; i++)
    {
      TreeNode *node = q.front();
      layer.push_back(node->val);
      if (node->left)
        q.push(node->left);
      if (node->right)
        q.push(node->right);
      q.pop();
    }
    ret.push_back(layer);
  }
  return ret;
}

//打印二叉树
void printBTree(TreeNode *head)
{
  if (!head)
    return;
  cout << head->val << " ";
  printBTree(head->left);
  printBTree(head->right);
}

int main()
{
  vector<TreeNode *> vec;
  for (size_t i = 0; i <= 10; i++)
  {
    vec.push_back(new TreeNode(i));
  }

  for (size_t i = 0; i <= 4; i++)
  {
    vec[i]->left = vec[2 * i + 1];
    vec[i]->right = vec[2 * i + 2];
  }

  // printBTree(vec[0]);
  // cout << endl;

  vector<vector<int>> ret = levelOrder(vec[0]);
  cout << "层序遍历:" << endl;
  for (int i = 0; i < ret.size(); i++)
  {
    for (int j = 0; j < ret[i].size(); j++)
    {
      cout << ret[i][j] << " ";
    }
    cout << endl;
  }
  return 0;
}