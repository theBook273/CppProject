#include <bits/stdc++.h>

using namespace std;

int dsu[109];

int parent(int x) {
  if (dsu[x] == x)
    return x;
  else
    return dsu[x] = parent(dsu[x]);
}

bool join(int x, int y) {
  int px = parent(x);
  int py = parent(y);
  if (py != px) {
    dsu[py] = px;
    return 1;
  }
  return 0;
}

bool comp(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b) {
  return a.second < b.second;
}

signed main() {
  freopen("CAU3.INP", "r", stdin);
  freopen("CAU3.OUT", "w", stdout);
  int n, x;
  cin >> n >> x;
  for (int i = 1; i <= n; i++) {
    dsu[i] = i;
  }
  vector<pair<pair<int, int>, int>> a;
  int v, u, d;
  while (cin >> v >> u >> d) {
    a.push_back({{v, u}, d});
  }
  sort(a.begin(), a.end(), comp);
  int tong = 0;
  for (auto i : a) {
    if (join(i.first.first, i.first.second)) {
      tong += i.second;
    }
  }
  cout << tong << "\n";
}
