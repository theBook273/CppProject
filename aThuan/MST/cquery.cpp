#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 273;

vector<int> color;
int dsu[MAXN];
unordered_map<int, int> sz[MAXN];

int parent(int p) { return (dsu[p] == p ? p : dsu[p] = parent(dsu[p])); }

void join(int a, int b) {
  a = parent(a);
  b = parent(b);

  if (a == b)
    return;

  if (sz[a].size() < sz[b].size())
    swap(a, b);

  for (auto [i, j] : sz[b]) {
    sz[a][i] += j;
  }
  dsu[b] = a;
}

signed main() {
  cin.tie()->sync_with_stdio(0);
  int n, q;
  cin >> n >> q;

  for (int temp, i = 1; i <= n; i++) {
    dsu[i] = i;
    cin >> temp;
    sz[i][temp]++;
  }

  int type, u, v;
  while (q--) {
    cin >> type >> u >> v;
    if (type == 1) {
      join(u, v);
    } else {
      cout << sz[parent(u)][v] << "\n";
    }
  }
}
