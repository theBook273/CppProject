#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 1e5;
const int oo = 1e18;

vector<int> id(N + 1, 0), low(N + 1, 0), scc(N + 1, 0),
    dem(N + 1, 0), adj[N + 1], roadOut(N + 1, 0);
vector<pair<int, int>> edge;
vector<bool> outStack(N + 1, 0);
stack<int> st;
int n, m, timer = 0, tplt = 0, res = oo;

void tarjan(int u) {
  id[u] = low[u] = ++timer;
  st.push(u);
  for (auto &v : adj[u]) {
    if (!outStack[v]) {
      if (low[v]) {
        low[u] = min(low[u], low[v]);
      } else {
        tarjan(v);
        low[u] = min(low[u], low[v]);
      }
    }
  }
  if (id[u] == low[u]) {
    int v;
    tplt++;
    do {
      v = st.top();
      st.pop();
      outStack[v] = 1;
      dem[tplt]++;
      scc[v] = tplt;
    } while (v != u);
  }
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> m;
  for (int u, v, i = 0; i < m; i++) {
    cin >> u >> v;
    adj[u].push_back(v);
    edge.push_back({u, v});
  }

  for (int i = 1; i <= n; i++) {
    if (!low[i]) {
      tarjan(i);
    }
  }

  for (auto &[u, v] : edge) {
    u = scc[u];
    v = scc[v];
    if (u != v) {
      roadOut[u]++;
    }
  }
  for (int i = 1; i <= tplt; i++) {
    if (!roadOut[i]) {
      res = min(res, dem[i]);
    }
  }
  cout << res;
}
