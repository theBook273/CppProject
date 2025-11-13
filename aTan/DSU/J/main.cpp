#include <bits/stdc++.h>
#define int long long

using namespace std;

vector<pair<int, int>> a;
vector<int> dsu, sz, res;
vector<bool> active;
int n;

int parent(int x) { return (dsu[x] == x ? x : dsu[x] = parent(dsu[x])); }
void join(int x, int y) {
  x = parent(x);
  y = parent(y);
  if (x != y) {
    sz[x] += sz[y];
    dsu[y] = x;
  }
}

signed main() {
  cin.tie()->sync_with_stdio(0);

  freopen("test", "r", stdin);
  freopen("testChuan", "w", stdout);

  int n;
  cin >> n;

  active.resize(n + 1, 0);
  sz.resize(n + 1, 1);
  dsu.resize(n + 1, 0);
  res.resize(n + 1, LLONG_MIN);
  a.resize(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i].first;
    a[i].second = i;
    dsu[i] = i;
  }

  sort(a.begin(), a.end(), greater<>());

  for (int i = 0; i < n; i++) {
    auto [x, id] = a[i];
    active[id] = 1;

    if (id + 1 <= n && active[id + 1]) {
      join(id, id + 1);
    }

    if (id - 1 >= 1 && active[id - 1]) {
      join(id, id - 1);
    }

    res[sz[parent(id)]] = max(res[sz[parent(id)]], x);
  }

  for (int i = n - 1; i >= 1; i--) {
    res[i] = max(res[i], res[i + 1]);
  }

  for (int i = 1; i <= n; i++) {
    cout << res[i] << " ";
  }
}
