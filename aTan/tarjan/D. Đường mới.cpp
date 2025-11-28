#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 1e5;

struct Edge {
  int from, to;
};

vector<Edge> edge;
vector<int> id, low, scc, edgeOf;
unordered_set<int> se[N + 1];
vector<int> adj[N + 1];
vector<bool> outstack;
unordered_map<int, vector<int>> mp;
stack<int> st;
int n, m, tplt = 0, timer = 0;

void tarjan(int u) {
  low[u] = id[u] = ++timer;
  st.push(u);
  for (auto v : adj[u]) {
    if (!outstack[v]) {
      if (!id[v]) {
        tarjan(v);
        low[u] = min(low[u], low[v]);
      } else {
        low[u] = min(low[u], low[v]);
      }
    }
  }
  if (id[u] == low[u]) {
    tplt++;
    int v;
    do {
      v = st.top();
      outstack[v] = 1;
      mp[tplt].push_back(v);
      scc[v] = tplt;
      st.pop();
    } while (v != u);
  }
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> m;

  outstack.resize(n + 1, 0);
  id.resize(n + 1, 0);
  low.resize(n + 1, 0);
  scc.resize(n + 1, 0);

  for (int u, v, i = 0; i < m; i++) {
    cin >> u >> v;
    if (u != v) {
      adj[u].push_back(v);
      edge.push_back({u, v});
    }
  }

  for (int i = 1; i <= n; i++) {
    if (!id[i]) {
      tarjan(i);
    }
  }

  int ans = 0;

  for (int i = 1; i <= tplt; i++) {
    ans += (mp[i].size() * (mp[i].size() - 1));
  }

  for (auto [u, v] : edge) {
    if (u != v && scc[u] == scc[v] && se[u].find(v) == se[u].end()) {
      se[u].insert(v);
      ans--;
    }
  }

  cout << ans;
}
