#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MOD = 1e9 + 7;

vector<int> a, dp;
int n, k;

void add(int &a, int &b) {
  a += b;
  if (a >= MOD) {
    a -= MOD;
  }
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  // freopen("COIN1.INP", "r", stdin);
  // freopen("COIN1.OUT", "w", stdout);

  cin >> n >> k;
  a.resize(n + 1, 0);
  dp.resize(k + 1, 0);

  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  dp[0] = 1;

  for (int i = 1; i <= k; i++) {
    for (int j = 1; j <= n; j++) {
      if (i >= a[j]) {
        add(dp[i], dp[i - a[j]]);
      }
    }
  }

  cout << dp[k];
}
