#include <bits/stdc++.h>
#define int long long

using namespace std;

const int oo = 1e18;

vector<vector<int>> a;
vector<int> bitCnt[20], f, dp;
int n, full;

string bin(int x) {
  string s;
  for (int i = 0; i < n; i++) {
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

  cin >> n;
  a.resize(n, vector<int>(n));

  for (auto &i : a) {
    for (auto &j : i) {
      cin >> j;
    }
  }

  full = (1 << n);

  dp.resize(full, -oo);
  f.resize(full, 0);

  f[0] = 0;
  dp[0] = 0;

  for (int mask = 0; mask < full; mask++) {
    vector<int> pos;
    for (int i = 0; i < n; i++) {
      if ((mask >> i) & 1) {
        pos.push_back(i);
      }
    }
    for (int i = 0; i < (int)pos.size(); i++) {
      for (int j = 0; j < i; j++) {
        f[mask] += a[pos[i]][pos[j]];
      }
    }
  }

  for (int mask = 0; mask < full; mask++) {
    for (int sub = mask; sub > 0; sub = (sub - 1) & mask) {
      if ((mask & sub) == sub) {
        dp[mask] = max(dp[mask], dp[mask ^ sub] + f[sub]);
      }
    }
  }

  cout << dp[full - 1];
}
