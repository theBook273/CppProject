#include <bits/stdc++.h>
#define int long

using namespace std;

const int N = 1e5;
const int MOD = 1e9 + 7;

int add(const int &a, const int &b) { return ((a % MOD) + (b % MOD)) % MOD; }
int mul(const int &a, const int &b) { return ((a % MOD) * (b % MOD)) % MOD; }

vector<int> adj[N + 5];
vector<vector<int>> dp(N + 5, vector<int>(2, 1));

void dfs(int u, int p) {
  for (auto v : adj[u]) {
    if (v == p) {
      continue;
    }

    dfs(v, u);

    dp[u][0] = mul(dp[u][0], add(dp[v][1], dp[v][0]));
    dp[u][0] %= MOD;
    dp[u][1] = mul(dp[u][1], dp[v][0]);
    dp[u][1] %= MOD;
  }
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  for (int u, v, i = 0; i < n - 1; i++) {
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  dfs(1, -1);

  cout << add(dp[1][0], dp[1][1]);
}
