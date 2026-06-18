#include <bits/stdc++.h>
#define int long long

using namespace std;

void solve() {
  string s;
  int n, k;
  cin >> n >> k >> s;
  vector<int> dem(n + 1, 0);
  for (int i = 0; i < n; i++) {
    dem[i % k] += (s[i] - '0');
  }
  bool check = 1;
  for (int i = 0; i < k; i++) {
    if (dem[i % k] % 2 != 0) {
      check = 0;
      break;
    }
  }

  cout << ((check) ? "YES\n" : "NO\n");
}

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
