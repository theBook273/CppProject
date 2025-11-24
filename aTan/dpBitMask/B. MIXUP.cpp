#include <bits/stdc++.h>
#include <string>
#define int long long

using namespace std;

const int MOD = 1e9;

int n, k;

string np(int x) {
  string s;
  for (int i = n - 1; i >= 0; i--) {
    if ((x >> i) & 1) {
      s.push_back('1');
    } else {
      s.push_back('0');
    }
  }
  return s;
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> k;
  vector<int> a(n);
  for (auto &i : a) {
    cin >> i;
  }

  int full = (1 << n);
  vector<vector<int>> dp(n + 1, vector<int>(full + 1, 0));

  for (int i = 0; i < n; i++) {
    dp[i][1 << i] = 1;
  }

  for (int mask = 0; mask < full; mask++) {
    vector<int> pos;
    for (int i = 0; i < n; i++) {
      if ((mask >> i) & 1) {
        pos.push_back(i);
      }
    }
    for (auto i : pos) {
      int pmask = mask ^ (1 << i);
      for (auto j : pos) {
        if (i != j && abs(a[i] - a[j]) > k) {
          dp[i][mask] += dp[j][pmask];
        }
        // cout << i << " " << np(mask) << " " << dp[i][mask] << "\n";
      }
      // cout << "\n";
    }
  }

  int res = 0;
  for (int i = 0; i < n; i++) {
    res += dp[i][full - 1];
  }
  cout << res;
}
