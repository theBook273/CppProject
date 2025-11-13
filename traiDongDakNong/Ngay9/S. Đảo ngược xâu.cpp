#include <bits/stdc++.h>
#define int long long

using namespace std;

const int INF = 4e18;

vector<string> s, rev;
vector<vector<int>> dp;
vector<int> e;
int n;

signed main() {
  cin.tie()->sync_with_stdio(0);
  cout.tie()->sync_with_stdio(0);

  freopen("reverse.inp", "r", stdin);
  freopen("reverse.out", "w", stdout);

  cin >> n;
  s.resize(n), rev.resize(n), e.resize(n), dp.resize(n, vector<int>(2, INF));

  for (int i = 0; i < n; i++) {
    cin >> e[i];
  }

  for (int i = 0; i < n; i++) {
    cin >> s[i];
    rev[i] = s[i];
    reverse(rev[i].begin(), rev[i].end());
  }

  dp[0][0] = 0;
  dp[0][1] = e[0];

  for (int i = 1; i < n; i++) {
    if (s[i - 1] <= s[i]) {
      dp[i][0] = min(dp[i][0], dp[i - 1][0]);
    }
    if (rev[i - 1] <= s[i]) {
      dp[i][0] = min(dp[i][0], dp[i - 1][1]);
    }

    if (s[i - 1] <= rev[i]) {
      dp[i][1] = min(dp[i][1], dp[i - 1][0] + e[i]);
    }
    if (rev[i - 1] <= rev[i]) {
      dp[i][1] = min(dp[i][1], dp[i - 1][1] + e[i]);
    }
  }

  int res = min(dp[n - 1][0], dp[n - 1][1]);
  cout << (res == INF ? -1 : res) << "\n";
}
