#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 5e4;
const int oo = 1e18;

int n, m;
vector<int> distTar, adj[N + 5];

namespace sub1 {

signed solve() {
  vector<int> check(n + 1, 0);
  int dem = 0;

  for (int i = 1; i <= n; i++) {
    if (distTar[i] != -1) {
      dem++;
      int r = i + distTar[i];
      int l = i - distTar[i];
      if (r <= n) {
        check[r]++;
      }
      if (l >= 1 && l != r) {
        check[l]++;
      }
    }
  }

  vector<int> res;
  for (int i = 1; i <= n; i++) {
    if (check[i] == dem) {
      res.push_back(i);
    }
  }

  cout << res.size() << "\n";
  for (auto i : res) {
    cout << i << " ";
  }

  return 0;
}

} // namespace sub1

namespace sub2 {

signed solve() {
  vector<int> dis(n + 1, oo);
  queue<int> q;
  q.push(1);
  dis[1] = 0;

  while (!q.empty()) {
    int u = q.front();
    q.pop();

    for (auto v : adj[u]) {
      if (dis[v] > dis[u] + 1) {
        dis[v] = dis[u] + 1;
        q.push(v);
      }
    }
  }

  vector<int> res;

  for (int i = 1; i <= n; i++) {
    if (dis[i] == distTar[1]) {
      res.push_back(i);
    }
  }

  cout << res.size() << "\n";
  for (auto i : res) {
    cout << i << " ";
  }

  return 0;
}

} // namespace sub2

namespace sub3 {

int dem = 0;
vector<int> res, dis, check;

void bfs(int start) {
  dis.assign(n + 1, oo);
  queue<int> q;
  q.push(start);
  dis[start] = 0;

  while (!q.empty()) {
    int u = q.front();
    q.pop();

    for (auto v : adj[u]) {
      if (dis[v] > dis[u] + 1) {
        dis[v] = dis[u] + 1;
        q.push(v);
      }
    }
  }

  for (int i = 1; i <= n; i++) {
    if (distTar[start] == dis[i]) {
      check[i]++;
    }
  }
}

signed solve() {
  check.resize(n + 1, 0);

  for (int i = 1; i <= n; i++) {
    if (distTar[i] != -1) {
      dem++;
      bfs(i);
    }
  }

  for (int i = 1; i <= n; i++) {
    if (check[i] == dem) {
      res.push_back(i);
    }
  }

  cout << res.size() << "\n";
  for (auto i : res) {
    cout << i << " ";
  }

  return 0;
}

} // namespace sub3

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("CROSS.INP", "r", stdin);
  freopen("CROSS.OUT", "w", stdout);

  cin >> n >> m;

  bool flag1 = 1;
  bool flag2 = 1;

  distTar.resize(n + 1, 0);
  for (int u, v, i = 0; i < m; i++) {
    cin >> u >> v;
    if (u + 1 != v) {
      flag1 = 0;
    }
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  for (int i = 1; i <= n; i++) {
    cin >> distTar[i];
    if (distTar[i] != -1 && i != 1) {
      flag2 = 0;
    }
  }

  if (flag1) {
    return sub1::solve();
  }
  if (flag2) {
    return sub2::solve();
  }
  return sub3::solve();

  return 0;
}
