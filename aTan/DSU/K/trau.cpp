#include <bits/stdc++.h>
#include <cstdio>
#define int long long

using namespace std;

set<int> alive;
vector<int> dsu;
int n, q;

void join(int win, int lose) {
  if (dsu[lose] == lose) {
    dsu[lose] = win;
  }
}

signed main() {
  cin.tie()->sync_with_stdio(0);

  freopen("test", "r", stdin);
  freopen("testTrau", "w", stdout);

  cin >> n >> q;

  dsu.resize(n + 1, 0);
  for (int i = 1; i <= n; i++) {
    dsu[i] = i;
    alive.insert(i);
  }

  int l, r, win;
  set<int> dead;
  while (q--) {
    cin >> l >> r >> win;
    for (auto i : alive) {
      if (i != win && l <= i && i <= r) {
        join(win, i);
        dead.insert(i);
      }
    }
    for (auto i : dead) {
      alive.erase(i);
    }
    dead.clear();
  }

  for (int i = 1; i <= n; ++i) {
    cout << (dsu[i] == i ? 0 : dsu[i]) << " ";
  }
}
