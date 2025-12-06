#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 1e5;

int n, k, arrest = 0;
vector<int> adj[N + 5];
vector<vector<int>> dp(N + 5, vector<int>(2, 0));

void dfs(int u, int p) {
  dp[u][1] = 0;
  dp[u][0] = 1;
  for (auto v : adj[u]) {
    if (v == p) {
      continue;
    }

    dfs(v, u);
  }

  int maxi = 0;

  for (auto v : adj[u]) {
    if (v == p) {
      continue;
    }

    maxi = max(maxi, dp[v][0]);
    dp[u][0] += dp[v][0];
  }

  dp[u][1] = maxi;

  if (dp[u][0] >= k) {
    arrest++;
    dp[u][0] = dp[u][1] = 0;
  }
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> k;
  for (int p, i = 2; i <= n; i++) {
    cin >> p;
    adj[p].push_back(i);
    adj[i].push_back(p);
  }

  dfs(1, -1);

  // for (int i = 1; i <= n; i++) {
  //   cout << i << " " << dp[i][0] << " " << dp[i][1] << "\n";
  // }

  cout << arrest;
}
