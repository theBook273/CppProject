#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 1e5;
const int lg = 20;

vector<vector<int>> parent(N + 1, vector<int>(lg + 1, 0));
vector<int> depth(N + 1, 0), light(N + 1), state(N + 1, 0), adj[N + 5];
int n, k, res = 0;

void dfsSetUp(int u, int p) {
  for (auto &v : adj[u]) {
    if (v != p) {
      depth[v] = depth[u] + 1;
      parent[v][0] = u;
      dfsSetUp(v, u);
    }
  }
}

void init() {
  for (int j = 1; j <= lg; j++) {
    for (int i = 1; i <= n; i++) {
      parent[i][j] = parent[parent[i][j - 1]][j - 1];
    }
  }
}

void calc(int u, int p) {
  for (int &v : adj[u]) {
    if (v != p) {
      calc(v, u);
      state[u] += light[v];
      state[u] %= 2;
    }
  }
  if (u != 1) {
    light[u] = state[u];
  }
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> k;

  for (int i = 1; i <= n; i++) {
    cin >> light[i];
  }

  for (int u, v, i = 0; i < n - 1; i++) {
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  dfsSetUp(1, -1);
  init();

  for (int x, i = 0; i < k; i++) {
    cin >> x;
    state[parent[x][0]] = !state[parent[x][0]];
  }

  calc(1, -1);
  for (int i = 1; i <= n; i++) {
    cout << light[i] << " ";
  }

  cout << res;
}
