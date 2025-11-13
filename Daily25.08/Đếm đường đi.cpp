#include <bits/stdc++.h>

using namespace std;

vector<int> a[5009];
vector<bool> check(5009, 0);
vector<int> temp;
int tong = 0;
int n, k1, k2;
int duongDi[5009][5009];

void dfs(int now, int dem, int root) {
  for (auto i : a[now]) {
    if (!check[i]) {
      check[i] = 1;
      dfs(i, dem + 1, root);
      check[i] = 0;
    }
  }
}

signed main() {
  cin.tie()->sync_with_stdio(0);
  cin >> n >> k1 >> k2;

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      duongDi[i][j] = 0;
    }
  }

  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;

    a[u].push_back(v);
    a[v].push_back(u);
    duongDi[u][v] = 1;
    duongDi[v][u] = 1;
  }

  for (int now = 1; now <= n; now++) {
    check.assign(5009, 0);
    check[now] = 1;
    dfs(now, 0, now);
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cout << duongDi[i][j] << " ";
    }
    cout << "\n";
  }

  cout << tong;
}
