#include <bits/stdc++.h>
#define int long long

using namespace std;

vector<int> dsu, cnt, maxn, minn;

int parent(int x) {
  if (dsu[x] == x) {
    return x;
  } else {
    dsu[x] = parent(dsu[x]);
    return dsu[x];
  }
}

void join(int u, int v) {
  u = parent(u);
  v = parent(v);
  if (u != v) {
    dsu[v] = u;
    cnt[u] += cnt[v];
    maxn[u] = max(maxn[u], maxn[v]);
    minn[u] = min(minn[u], minn[v]);
  }
}

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m;
  cin >> n >> m;
  dsu.push_back(0);
  maxn.push_back(0);
  minn.push_back(0);
  cnt.push_back(0);
  for (int i = 1; i <= n; i++) {
    dsu.push_back(i);
    cnt.push_back(1);
    maxn.push_back(i);
    minn.push_back(i);
  }

  string s;
  int a, b;
  while (m--) {
    cin >> s;
    if (s == "union") {
      cin >> a >> b;
      join(a, b);
    } else if (s == "get") {
      cin >> a;
      int p = parent(a);
      cout << minn[p] << " " << maxn[p] << " " << cnt[p] << "\n";
    }
  }
}
