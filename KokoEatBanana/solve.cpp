#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int minEatingSpeed(vector<int> &piles, int h) {
    int res = 1e9;
    int l = 1, r = *max_element(piles.begin(), piles.end()), m, temp;
    while (l <= r) {
      m = (r + l) / 2;
      temp = 0;
      for (auto i : piles) {
        temp += ceil(double(i) / double(m));
      }
      if (temp <= h) {
        res = min(res, m);
        r = m - 1;
      } else {
        l = m + 1;
      }
    }
    return res;
  }
};

signed main() {
  int n, h;
  cin >> n >> h;
  vector<int> a(n);
  for (auto &i : a)
    cin >> i;
  Solution test;
  cout << test.minEatingSpeed(a, h);
}
