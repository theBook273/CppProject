#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int maxArea(vector<int> &heights) {
    int l = 0, r = heights.size() - 1;
    int res = (r - l) * min(heights[l], heights[r]);
    while (l <= r) {
      res = max(res, (r - l) * min(heights[l], heights[r]));
      if (heights[l] <= heights[r]) {
        l++;
      } else {
        r--;
      }
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
  cout << test.maxArea(a);
}
