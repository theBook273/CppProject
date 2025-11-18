#include <bits/stdc++.h>
#define int long long

using namespace std;

struct Edge {
  int from, to, len;
};

vector<Edge> edge;
vector<int> cost;
vector<int> dsu;
int n, m;

int parent(int x) { return (dsu[x] == x ? x : dsu[x] = parent(dsu[x])); }
void join(int x, int y) {
  x = parent(x);
  y = parent(y);

  if (x != y) {
    if (cost[x] > cost[y]) {
      swap(x, y);
    }
    dsu[y] = x;
  }
}

signed main() {
  cin.tie()->sync_with_stdio(0);
  cin >> n >> m;

  cost.resize(n + 1);
  dsu.resize(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> cost[i];
    dsu[i] = i;
  }

  for (int u, v, i = 0; i < m; i++) {
    cin >> u >> v;
    join(u, v);
  }

  vector<int> needBridge;
  for (int i = 1; i <= n; i++) {
    if (dsu[i] == i) {
      needBridge.push_back(cost[i]);
    }
  }

  sort(needBridge.begin(), needBridge.end());

  int tong = 0;
  for (int i = 1; i < (int)needBridge.size(); i++) {
    tong += needBridge[0] + needBridge[i];
  }

  cout << tong << "\n";
}
