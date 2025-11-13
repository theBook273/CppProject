#include <bits/stdc++.h>
#define int long long

using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);

  for (auto &i : a) {
    cin >> i;
  }

  if (n >= 2) {
    reverse(a.begin(), a.end());

    vector<int> pre(n);
    pre[0] = 0;
    pre[1] = a[0];
    for (int i = 2; i < n; i++) {
      pre[i] = pre[i - 1] + a[i - 1];
    }

    vector<int> maxn(n, 0);
    maxn[n - 1] = a[n - 1];
    for (int i = n - 2; i >= 0; i--) {
      maxn[i] = max(maxn[i + 1], a[i]);
    }

    for (int i = 1; i <= n; i++) {
      cout << pre[i - 1] + maxn[i - 1] << " ";
    }
  } else {
    cout << a[0];
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
