#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e5 + 273;

struct Edge {
  int from, to, len, id;
  bool operator<(const Edge &other) const { return len < other.len; }
};

vector<Edge> edge;
vector<int> adj[maxn];
map<int, int> mp;
int dsu[maxn];

int parent(int p) { return (dsu[p] == p) ? p : dsu[p] = parent(dsu[p]); }

bool join(int a, int b) {
  a = parent(a);
  b = parent(b);
  if (a == b)
    return 0;
  dsu[a] = b;
  return 1;
}

void dfs(int u, int pEdge, vector<vector<pair<int, int>>> &g, vector<int> &id,
         vector<int> &low, int &timer, vector<string> &ans) {
  id[u] = low[u] = ++timer;
  for (auto [v, eid] : g[u]) {
    if (eid == pEdge)
      continue;
    if (!id[v]) {
      dfs(v, eid, g, id, low, timer, ans);
      low[u] = min(low[u], low[v]);
      if (low[v] > id[u]) {
        ans[eid] = "Yes";
      }
    } else {
      low[u] = min(low[u], id[v]);
    }
  }
}

signed main() {
  cin.tie()->sync_with_stdio(0);
  int n, m;
  cin >> n >> m;
  edge.resize(m);

  for (int i = 1; i <= n; ++i) {
    dsu[i] = i;
  }

  for (int i = 0; i < m; i++) {
    cin >> edge[i].from >> edge[i].to >> edge[i].len;
    edge[i].id = i;
  }
  sort(edge.begin(), edge.end());
  vector<Edge> toCheck;

  vector<string> ans(m, "No");

  for (int i = 0; i < m - 1; i++) {
    toCheck.push_back(edge[i]);
    while (edge[i].len == edge[i + 1].len) {
      toCheck.push_back(edge[i + 1]);
      i++;
    }

    vector<int> node;
    for (auto &i : toCheck) {
      int pu = parent(i.from);
      int pv = parent(i.to);
      if (pu != pv) {
        node.push_back(pu);
        node.push_back(pv);
      }
    }
    sort(node.begin(), node.end());
    node.erase(unique(node.begin(), node.end()), node.end());

    auto idx = [&](int x) {
      return int(lower_bound(node.begin(), node.end(), x) - node.begin());
    };

    int k = node.size();
    vector<vector<pair<int, int>>> g(k);

    for (auto [from, to, len, id] : toCheck) {
      int pu = parent(from);
      int pv = parent(to);
      if (pu == pv)
        continue;
      int a = idx(pu), b = idx(pv);
      g[a].push_back({b, id});
      g[b].push_back({a, id});
    }

    vector<int> id(k, 0), low(k, 0);
    int timer = 0;
    for (int v = 0; v < k; v++)
      if (!id[v])
        dfs(v, -1, g, id, low, timer, ans);

    for (auto i : toCheck) {
      join(i.from, i.to);
    }

    toCheck.clear();
  }

  for (auto i : ans) {
    cout << i << " ";
  }
}
