#include <bits/stdc++.h>

using namespace std;

struct Edge {
  int to;
  string color;
};

const int maxn = 1e5 + 273;

vector<Edge> adj[maxn];
vector<string> state;
vector<int> disToPau;
vector<int> disToMar;
int n, pau, mar;

void dfsPau(int x, int p) {
  for (auto [to, color] : adj[x]) {
    if (to == p)
      continue;
    if (color != "blue" && color != "magenta")
      continue;
    disToPau[to] = disToPau[x] + 1;
    dfsPau(to, x);
  }
}

void dfsMar(int x, int p) {
  for (auto [to, color] : adj[x]) {
    if (to == p)
      continue;
    if (color != "red" && color != "magenta")
      continue;
    disToMar[to] = disToMar[x] + 1;
    dfsMar(to, x);
  }
}

void dfsSolve(int x, int p) {
  if (state[x] != "pau" && state[x] != "mar")
    int dis = disToPau[x] + disToMar[x];
}

signed main() {
  cin.tie()->sync_with_stdio(0);
  cin >> n >> pau >> mar;
  disToPau.resize(n + 1, -1);
  disToMar.resize(n + 1, -1);
  string color;
  for (int u, v, i = 0; i < n - 1; i++) {
    cin >> u >> v >> color;
    adj[u].push_back({v, color});
    adj[v].push_back({u, color});
  }

  disToPau[pau] = -1;
  dfsPau(pau, pau);

  disToMar[mar] = -1;
  dfsMar(mar, mar);
}
