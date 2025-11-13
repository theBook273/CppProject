#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n, k, m;
  cin >> n >> k >> m;
  vector<int> a(n);
  for (auto &i : a) {
    cin >> i;
  }
  vector<int> pre(n);
  pre[0] = a[0];
  for (int i = 1; i < n; i++) {
    pre[i] = pre[i - 1] + a[i];
  }
  for (auto i : pre) {
    cout << i << " ";
  }
  cout << "\n";
}

signed main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
