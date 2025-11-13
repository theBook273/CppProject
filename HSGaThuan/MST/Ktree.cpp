#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e6 + 273;

int n, k, ans = 0;
vector<int> adj[MAXN];
bool removed[MAXN];
int subtree[MAXN];

void subTreeSize(int &u, int p) {
  subtree[u] = 1;
  for (int v : adj[u]) {
    if (v != p && !removed[v]) {
      subTreeSize(v, u);
      subtree[u] += subtree[v];
    }
  }
}

int findCen(int &u, int p, int total) {
  for (int v : adj[u]) {
    if (v != p && !removed[v]) {
      if (subtree[v] * 2 > total) {
        return findCen(v, u, total);
      }
    }
  }
  return u;
}

void collectDepth(int &u, int &p, int depth, vector<int> &depths) {
  if (depth > k)
    return;
  depths.push_back(depth);
  for (int v : adj[u]) {
    if (v != p && !removed[v]) {
      collectDepth(v, u, depth + 1, depths);
    }
  }
}

void decomp(int u) {
  subTreeSize(u, -1);
  int c = findCen(u, -1, subtree[u]);
  removed[c] = 1;

  vector<int> cnt(k + 1, 0);
  cnt[0] = 1;

  for (int v : adj[c]) {
    if (!removed[v]) {
      vector<int> depths;
      collectDepth(v, c, 1, depths);

      for (int d : depths) {
        if (d <= k)
          ans += cnt[k - d];
      }

      for (int d : depths) {
        if (d <= k)
          cnt[d]++;
      }
    }
  }

  for (int v : adj[c]) {
    if (!removed[v]) {
      decomp(v);
    }
  }
}

signed main() {
  cin.tie()->sync_with_stdio(0);

  cin >> n >> k;
  for (int u, v, i = 1; i <= n - 1; i++) {
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  decomp(1);
  cout << ans << "\n";
}
