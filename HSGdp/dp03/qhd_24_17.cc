#include <bits/stdc++.h>
#define int long long

using namespace std;

struct Way {
  int to, len;
};

const int MAXN = 1e5 + 5;
const int MOD = 1e9 + 7;

vector<Way> adj[MAXN];
int depth[MAXN];
int res = 0;

// void dfs(int u, int p) {
//   for (auto [v, len] : adj[u]) {
//     if (v != p) {
//       depth[v] = depth[u] % MOD * len % MOD;
//       dfs(v, u);
//     }
//   }
// }

int dfs(int u, int p) {
  int sum = 0;

  for (auto [to, len] : adj[u]) {
    if (to != p) {
      int child = dfs(to, u);
      int val = (len % MOD) * (1 + child) % MOD;
      res = (res + sum * val % MOD) % MOD;
      sum = (sum + val) % MOD;
    }
  }
  res = (res + sum) % MOD;

  return sum;
}

signed main() {
  cin.tie()->sync_with_stdio(0);

  freopen("MTREE.inp", "r", stdin);
  freopen("MTREE.out", "w", stdout);

  int n;
  cin >> n;
  for (int u, v, w, i = 0; i < n - 1; i++) {
    cin >> u >> v >> w;
    adj[u].push_back({v, w});
    adj[v].push_back({u, w});
  }

  // int tong = 0;
  // for (int i = 1; i <= n; i++) {
  //   depth[i] = 1;
  //   dfs(i, i);
  //   depth[i] = 0;
  //   for (int j = i + 1; j <= n; j++) {
  //     tong += depth[j];
  //   }
  // }
  // cout << tong << "\n";

  dfs(1, 1);
  cout << res;
}
