#include <bits/stdc++.h>
#define int long long

using namespace std;

struct Edge {
  int from, to, len;
  const bool operator<(const Edge &other) { return len < other.len; }
};

const int N = 1e6;

int n, m;
vector<int> dsu, sub, ans;
vector<pair<int, int>> adj[N + 5];
vector<Edge> edge;

int parent(int x) { return (dsu[x] == x ? x : dsu[x] = parent(dsu[x])); }
bool join(int a, int b) {
  a = parent(a);
  b = parent(b);
  if (a != b) {
    dsu[a] = b;
    return 1;
  }
  return 0;
}

void dfs(int u, int p) {
  sub[u] = 1;
  for (auto &[v, w] : adj[u]) {
    if (v == p) {
      continue;
    }

    dfs(v, u);
    sub[u] += sub[v];
  }
}

void add_bin(vector<int> &ans, int x, int sh) {
  int pos = sh;
  while (x > 0) {
    int bit = x & 1;
    int carry = bit;

    while (carry) {
      if (pos >= (int)ans.size()) {
        ans.push_back(0);
      }
      int val = ans[pos] + carry;
      ans[pos] = val & 1;
      carry = val >> 1;
      pos++;
    }

    x >>= 1;
    sh++;
    pos = sh;
  }
}

void calc(int u, int p) {
  for (auto &[v, w] : adj[u]) {
    if (v == p) {
      continue;
    }

    int pa = sub[v] * (n - sub[v]);

    add_bin(ans, pa, w);

    calc(v, u);
  }
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  dsu.resize(N + 1, 0);
  sub.resize(N + 1, 0);
  ans.resize(N + 5, 0);
  iota(dsu.begin(), dsu.end(), 0);

  cin >> n >> m;
  for (int u, v, w, i = 0; i < m; i++) {
    cin >> u >> v >> w;
    edge.push_back({u, v, w});
  }

  sort(edge.begin(), edge.end());
  int _ = 0;
  for (auto &[u, v, w] : edge) {
    if (join(u, v)) {
      adj[u].push_back({v, w});
      adj[v].push_back({u, w});
      _++;
      if (_ == n - 1) {
        break;
      }
    }
  }

  dfs(1, -1);

  calc(1, -1);

  int start = N + 4;
  while (start > 0 && ans[start] == 0) {
    start--;
  }

  for (int i = start; i >= 0; i--) {
    cout << ans[i];
  }
}
