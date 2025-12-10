#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MOD = 1e9 + 7;

int n, x;
vector<int> a, dp;

void addMod(int &a, int b) {
  a += b;
  if (a >= MOD) {
    a -= MOD;
  }
}

int mulmod(long long a, long long b) { return (int)((a * b) % MOD); }

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("CODING.INP", "r", stdin);
  freopen("CODING.OUT", "w", stdout);

  cin >> n >> x;
  a.resize(n, 0);
  dp.resize(x + 1, 0);

  for (auto &i : a) {
    cin >> i;
  }

  sort(a.begin(), a.end());

  vector<vector<int>> dp(n + 1, vector<int>(x + 1, 0));
  dp[0][0] = 1;

  for (int i = 0; i < n; i++) {
    int diff = (i == 0 ? 0 : a[i] - a[i - 1]);

    vector<vector<int>> dp2(n + 1, vector<int>(x + 1, 0));
    for (int k = 0; k <= n; k++) {
      for (int s = 0; s <= x; s++) {
        int cur = dp[k][s];
        if (!cur) {
          continue;
        }

        int s2 = s + diff * k;
        if (s2 > x) {
          continue;
        }

        addMod(dp2[k + 1][s2], cur);

        addMod(dp2[k][s2], cur);

        if (k > 0) {
          addMod(dp2[k][s2], mulmod(cur, k));
          addMod(dp2[k - 1][s2], mulmod(cur, k));
        }
      }
    }

    dp.swap(dp2);
  }

  int ans = 0;
  for (int i = 0; i <= x; i++) {
    addMod(ans, dp[0][i]);
  }

  cout << ans;
}
