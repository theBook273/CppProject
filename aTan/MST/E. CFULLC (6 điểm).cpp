#include <bits/stdc++.h>

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
    if (x > y) {
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
}
