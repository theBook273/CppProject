#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main() {
  cin.tie()->sync_with_stdio(0);
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &i : a) {
    cin >> i;
  }

  vector<int> pre(n);
  pre[0] = a[0];
  for (int i = 1; i < n; i++) {
    pre[i] = pre[i - 1] + a[i];
  }

  int q;
  cin >> q;
  int l, r;
  while (q--) {
    cin >> l >> r;
    l--;
    r--;
    cout << pre[r] - ((!l) ? 0 : pre[l - 1]) << "\n";
  }
}
