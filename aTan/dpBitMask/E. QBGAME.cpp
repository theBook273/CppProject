#include <bits/stdc++.h>
#define int long long

using namespace std;

const int oo = 1e18;

vector<int> valid;
int n;

string bin(int x) {
  string s;
  for (int i = 0; i < 8; i++) {
    char ins = '0';
    if ((x >> i) & 1) {
      ins = '1';
    }
    s.push_back(ins);
  }
  return s;
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int full = (1 << 8);

  for (int mask = 0; mask < full; mask++) {
    bool flag = 1;
    vector<int> pos;
    for (int i = 0; i < 8; i++) {
      if ((mask >> i) & 1) {
        pos.push_back(i);
      }
    }
    if (pos.size() >= 2) {
      for (int i = 0; i < (int)pos.size() - 1; i++) {
        if (pos[i] + 1 == pos[i + 1]) {
          flag = 0;
          break;
        }
      }
    }
    if (flag) {
      valid.push_back(mask);
    }
  }

  cin >> n;
  vector<vector<int>> a(8, vector<int>(n));
  for (auto &i : a) {
    for (auto &j : i) {
      cin >> j;
    }
  }

  vector<vector<int>> dp(n, vector<int>(full, -oo));

  for (int i = 0; i < n; i++) {
    for (auto mask : valid) {
      int sum = 0;
      for (int x = 0; x < 8; x++) {
        if ((mask >> x) & 1) {
          sum += a[x][i];
        }
      }
      if (i == 0) {
        dp[i][mask] = sum;
        continue;
      }
      for (auto pmask : valid) {
        if (!(pmask & mask)) {
          dp[i][mask] = max(dp[i][mask], dp[i - 1][pmask] + sum);
        }
      }
    }
  }

  int res = -oo;
  for (int i = 0; i < full; i++) {
    res = max(res, dp[n - 1][i]);
  }
  cout << res;
}
