#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int findMin(vector<int> &nums) {
    if (nums[nums.size() - 1] - nums[0] > 0 || nums.size() < 2) {
      return nums[0];
    }
    int res = 1e9;
    int l = 1, r = nums.size() - 1, m;
    while (l <= r) {
      m = (l + r) / 2;
      if (nums[m] - nums[0] < 0) {
        res = min(res, nums[m]);
        r = m - 1;
      } else {
        l = m + 1;
      }
    }
    return res;
  }
};

signed main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &i : a)
    cin >> i;
  Solution test;
  cout << test.findMin(a);
}
