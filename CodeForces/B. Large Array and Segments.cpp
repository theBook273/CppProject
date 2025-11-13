#include <bits/stdc++.h>
#define int long long

using namespace std;

void solve() {
  int n, k, x;
  cin >> n >> k >> x;
  vector<int> a(n), pre(n * k + 5);
  for (auto &i : a) {
    cin >> i;
  }
  pre[0] = a[0];
  for (int i = 1; i < n * k; i++) {
    pre[i] = pre[i - 1] + a[i % n];
  }
  for (int i = 0; i < n * k; i++) {
    cout << pre[i] << " ";
  }
  cout << "\n";
}

signed main() {
  cin.tie()->sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
