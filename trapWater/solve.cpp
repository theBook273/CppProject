#include <bits/stdc++.h>

using namespace std;
class Solution {
public:
  int trap(vector<int> &height) {
    int res = 0;
    vector<int> suffix(height.size()), prefix(height.size());
    prefix[0] = height[0];
    for (int i = 1; i < height.size(); i++) {
      prefix[i] = max(prefix[i - 1], height[i]);
    }
    suffix[height.size() - 1] = height[height.size() - 1];
    for (int i = height.size() - 2; i >= 0; i--) {
      suffix[i] = max(suffix[i + 1], height[i]);
    }
    for (int i = 0; i < height.size(); i++) {
      res += min(prefix[i], suffix[i]) - height[i];
    }
    return res;
  }
};

signed main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &i : a) {
    cin >> i;
  }
  Solution test;
  cout << test.trap(a);
}
