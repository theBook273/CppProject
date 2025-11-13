#include <bits/stdc++.h>

using namespace std;

signed main() {
  cin.tie()->sync_with_stdio(0);
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &i : a) {
    cin >> i;
  }
  int maxn = *max_element(a.begin(), a.end());
  vector<int> mp(maxn + 5, 0);
  for (auto i : a) {
    mp[i]++;
  }
  int res = 0;
  for (int i = maxn; i >= 1; i--) {
    int cnt = 0;
    for (int j = i; j <= maxn; j += i) {
      cnt += mp[j];
    }
    if (cnt >= 2) {
      cout << i;
      break;
    }
  }
}
