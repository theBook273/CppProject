#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<int> a(n + 1, 0);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  vector<int> pre(n + 1, 0);
  for (int i = 1; i <= n; i++) {
    pre[i] = pre[i - 1] + a[i];
  }

  int t;
  cin >> t;
  while (t--) {
    int a, b;
    cin >> a >> b;
    cout << pre[b] - pre[a - 1] << "\n";
  }
}
