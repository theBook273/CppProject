#include <bits/stdc++.h>
#define int long long

using namespace std;

const int oo = 1e18;

int n, k;

vector<int> a, pre;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> k;

  a.resize(n + 1, 0);
  pre.resize(n + 1, 0);

  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    pre[i] = pre[i - 1] + a[i];
  }

  int ans = -oo;
  int mini = oo;

  for (int r = 1; r <= n; r++) {
    if (r - k + 1 >= 1) {
      mini = min(mini, pre[r - k]);
      ans = max(ans, pre[r] - mini);
    }
  }

  cout << ans;
}
