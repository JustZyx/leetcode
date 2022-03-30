#include <iostream>
#include <vector>
using namespace std;

// 接雨水
// 当前柱子小于等于柱子左边和右边最高的
// 根据木桶理论,那么当前柱子所能接雨水的量取决于两边最短的柱子和当前柱子的高度差
// min(left[i], right[i]) - nums[i]
int trap(vector<int>& height) {
  // left:当前柱子左边最高的柱子
  // right:当前柱子右边最高的柱子
  vector<int> left(height), right(height);

  // left[0] == height[0]; right[-1] == height[-1]
  for (int i = 1; i < left.size(); i++) {
    left[i] = max(left[i - 1], height[i]);
  }
  for (int j = right.size() - 2; j >= 0; j--) {
    right[j] = max(right[j + 1], right[j]);
  }

  int water = 0;  //雨水量
  for (int k = 0; k < height.size(); k++) {
    water += (min(left[k], right[k]) - height[k]);
  }
  return water;
}

int main() {
  vector<int> nums1 = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
  vector<int> nums2 = {4, 2, 0, 3, 2, 5};
  cout << trap(num1) << endl;
  cout << trap(num2) << endl;
  return 0;
}