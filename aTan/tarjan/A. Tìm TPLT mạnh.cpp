#include <bits/stdc++.h>

using namespace std;

const int N = 1e4;

vector<int> id(N + 1, 0), low(N + 1, 0), adj[N + 5];
vector<bool> outStack(N + 1, 0);
stack<int> st;
int n, m, timer = 0, tplt = 0;

void tajan(int u) {
  id[u] = low[u] = ++timer;
  st.push(u);
  for (auto &v : adj[u]) {
    if (!outStack[v]) {
      if (low[v] != 0) {
        low[u] = min(low[u], low[v]);
      } else {
        tajan(v);
        low[u] = min(low[u], low[v]);
      }
    }
  }
  if (id[u] == low[u]) {
    tplt++;
    int v;
    cout << tplt << ": ";
    do {
      v = st.top();
      cout << v << " ";
      outStack[v] = 1;
      st.pop();
    } while (v != u);
    cout << "\n";
  }
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> m;

  for (int u, v, i = 0; i < m; i++) {
    cin >> u >> v;
    adj[u].push_back(v);
  }

  for (int i = 1; i <= n; i++) {
    if (!low[i]) {
      tajan(i);
    }
  }

  cout << tplt << "\n";
}
