#include <bits/stdc++.h>
#define int long long

using namespace std;

const int oo = 1e18;

int n, w;

namespace sub1 {
const int N = 100;

int ww[N + 5], vv[N + 5];
int vs = 0;

signed solve() {
  for (int i = 0; i < n; i++) {
    cin >> ww[i] >> vv[i];
  }

  int full = (1 << n);
  for (int mask = 0; mask < full; mask++) {
    vector<int> pos;
    for (int i = 0; i < n; i++) {
      if ((mask >> i) & 1) {
        pos.push_back(i);
      }
    }

    int wt = 0, vt = 0;
    for (int i : pos) {
      wt += ww[i];
      vt += vv[i];
    }

    if (vt > vs && wt <= w) {
      vs = vt;
    }
  }

  cout << vs;
  return 0;
}
} // namespace sub1

namespace sub2 {

const int N = 100;

int ww[N + 5], vv[N + 5];

signed solve() {
  for (int i = 1; i <= n; i++) {
    cin >> ww[i] >> vv[i];
  }

  vector<int> dp(w + 1, 0);
  for (int i = 1; i <= n; i++) {
    for (int j = w; j >= ww[i]; j--) {
      dp[j] = max(dp[j], dp[j - ww[i]] + vv[i]);
    }
  }

  cout << *max_element(dp.begin(), dp.end());

  return 0;
}

} // namespace sub2

namespace sub3 {

const int N = 1e5;

int ww[N + 5], vv[N + 5], V = 0;

signed solve() {
  for (int i = 1; i <= n; ++i) {
    cin >> ww[i] >> vv[i];
    V += vv[i];
  }

  vector<int> dp(V + 1, 1e18);
  dp[0] = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = V; j >= vv[i]; j--) {
      dp[j] = min(dp[j], dp[j - vv[i]] + ww[i]);
    }
  }

  for (int i = V; i >= 0; i--) {
    if (dp[i] <= w) {
      cout << i;
      break;
    }
  }

  return 0;
}

} // namespace sub3

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> w;

  if (n <= 20) {
    return sub1::solve();
  }

  if (n <= 100 && w <= 1e5) {
    return sub2::solve();
  }

  return sub3::solve();
}
