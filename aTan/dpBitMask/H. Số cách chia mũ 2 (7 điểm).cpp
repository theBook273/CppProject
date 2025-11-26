#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MOD = 1e9 + 7;

int maskof(int x) { return (1LL << x); }
bool on(int x, int i) { return (((x) >> (i)) & 1); }

vector<vector<int>> precal, dp, a;
int n, m;

void add(int &a, int &b) {
  a += b;
  if (a >= MOD) {
    a -= MOD;
  }
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> m;
  a.resize(n + 1, vector<int>(m + 1, 0));
  for (int x, i = 0; i < n; i++) {
    cin >> x;
    for (int hat, j = 0; j < x; j++) {
      cin >> hat;
      hat--;
      a[i][hat] = 1;
    }
  }

  int full = maskof(n);
  precal.resize(m + 1);
  for (int i = 0; i < full; i++) {
    precal[__builtin_popcountll(i)].push_back(i);
  }

  dp.resize(n + 1, vector<int>(full, 0));
  dp[0][0] = 1;
  for (int i = 1; i <= n; i++) {
    for (auto mask : precal[i]) {
      vector<int> pos;
      for (int x = 0; x < m; x++) {
        if (on(mask, x)) {
          pos.push_back(x);
        }
      }
      for (auto j : pos) {
        if (a[i - 1][j] == 1) {
          add(dp[i][mask], dp[i - 1][mask ^ (1LL << j)]);
        }
      }
    }
  }

  int ans = 0;
  for (auto mask : precal[n]) {
    add(ans, dp[n][mask]);
  }
  cout << ans;
}
