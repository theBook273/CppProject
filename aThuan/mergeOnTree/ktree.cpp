#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e6 + 5;

vector<int> adj[MAXN];
int sz[MAXN], in[MAXN], out[MAXN], depth[MAXN], pos[MAXN], cnt[MAXN];
int times = 0, n, k, res = 0;

void calc(int u, int p) {
  sz[u] = 1;
  times++;
  in[u] = times;
  pos[times] = u;
  for (int v : adj[u]) {
    if (v == p)
      continue;
    depth[v] = depth[u] + 1;
    calc(v, u);
    sz[u] += sz[v];
  }
  out[u] = times;
}

void dfs(int u, int p, bool isBig) {
  int bigChild = -1;
  for (int x : adj[u]) {
    if (x != p && (bigChild == -1 || sz[bigChild] < sz[x])) {
      bigChild = x;
    }
  }

  for (int v : adj[u]) {
    if (v == p || v == bigChild)
      continue;
    dfs(v, u, 0);
  }

  if (bigChild != -1) {
    dfs(bigChild, u, 1);
  }

  res += cnt[k + depth[u]];
  cnt[depth[u]]++;
  for (int v : adj[u]) {
    if (v == p || v == bigChild) {
      continue;
    }

    for (int i = in[v]; i <= out[v]; i++) {
      int d = k + 2 * depth[u] - depth[pos[i]];
      if (d >= 0)
        res += cnt[d];
    }

    for (int i = in[v]; i <= out[v]; i++) {
      cnt[depth[pos[i]]]++;
    }
  }

  if (!isBig) {
    for (int i = in[u]; i <= out[u]; i++) {
      cnt[depth[pos[i]]]--;
    }
  }
}

signed main() {
  cin.tie()->sync_with_stdio(0);
  cin >> n >> k;

  for (int u, v, i = 0; i < n - 1; i++) {
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  calc(1, 1);
  dfs(1, 1, 1);
  cout << res;
}
