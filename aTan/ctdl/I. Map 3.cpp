#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main() {
  cin.tie()->sync_with_stdio(0);
  int n;
  cin >> n;

  vector<int> a(n + 1);
  map<int, vector<int>> mp;

  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    mp[a[i]].push_back(i);
  }

  int q, l, r, x, tong = 0;
  cin >> q;
  while (q--) {
    tong = 0;
    cin >> l >> r >> x;
    if (!mp.count(x)) {
      cout << 0 << "\n";
      continue;
    }
    for (auto i : mp[x]) {
      if (l <= i && i <= r) {
        tong++;
      }
    }
    cout << tong << "\n";
  }
}
