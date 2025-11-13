#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAXN = 5e5 + 5;

vector<int> dsu, a, res, que;
vector<bool> mark;
set<int> se;
int n, t, ans = 0;

int parent(int x) { return (dsu[x] == x ? x : dsu[x] = parent(dsu[x])); }

void join(int x, int y) {
  x = parent(x);
  y = parent(y);
  if (x != y) {
    a[x] += a[y];
    dsu[y] = x;
  }
  ans = max(ans, a[x]);
}

signed main() {
  cin.tie()->sync_with_stdio(0);
  cin >> n >> t;

  dsu.resize(n);
  a.resize(n);
  mark.resize(n, 0);
  res.resize(t, 0);
  que.resize(t, 0);

  for (int i = 0; i < n; i++) {
    cin >> a[i];
    dsu[i] = i;
  }

  for (int i = 0; i < t; i++) {
    cin >> que[i];
    que[i]--;
    mark[que[i]] = 1;
  }

  for (int now = 0, i = 0; i < n; i++) {
    if (mark[i] == 1) {
      now = i + 1;
      continue;
    }
    join(now, i);
  }

  for (int i = t - 1; i >= 0; i--) {
    int now = que[i];
    res[i] = ans;

    join(now, now);

    if (now + 1 < n && !mark[now + 1]) {
      join(now, now + 1);
    }

    if (now - 1 >= 0 && !mark[now - 1]) {
      join(now, now - 1);
    }

    mark[now] = 0;
  }

  for (auto i : res) {
    cout << i << "\n";
  }
}
