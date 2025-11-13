#include <bits/stdc++.h>
#define int long long

using namespace std;

void solve() {
  int n, c;
  cin >> n >> c;
  map<int, int> mp;
  vector<bool> check(n, 1);
  for (int i = 0; i < n; i++) {
    int temp;
    cin >> temp;
    mp[temp]++;
  }
  for (int i = 0; i < n; i++) {
    auto p = mp.upper_bound(c);
    if (p != mp.begin()) {
      p--;
      mp[p->first]--;
      if (mp[p->first] == 0) {
        mp.erase(p->first);
      }
    }
    c /= 2;
  }
  int tong = 0;
  for (auto i : mp) {
    tong += i.second;
  }
  cout << tong << "\n";
}

signed main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
