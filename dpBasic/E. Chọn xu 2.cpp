#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;

void add(int &a, int b) {
  a += b;
  if (a >= MOD) {
    a -= MOD;
  }
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, x;
  cin >> n >> x;

  vector<int> dp(x + 1, 0), a(n);
  for (auto &i : a) {
    cin >> i;
  }

  dp[0] = 1;

  for (int coin : a) {
    for (int i = coin; i <= x; i++) {
      add(dp[i], dp[i - coin]);
    }
  }

  cout << dp[x];
}
