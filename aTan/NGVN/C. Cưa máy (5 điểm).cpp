#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e6 + 5;

struct query {
  int x, id;
  bool operator<(const query &other) const { return x > other.x; }
};

int a[MAXN], res[MAXN];
int n, q;
vector<query> que;

bool check(int h, int m) {
  int tong = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] > h) {
      tong += a[i] - h;
    }
  }
  return tong >= m;
}

signed main() {
  cin.tie()->sync_with_stdio(0);

  freopen("TLE.INP", "r", stdin);
  freopen("TLE.OUT", "w", stdout);

  cin >> n >> q;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  for (int x, i = 0; i < q; i++) {
    cin >> x;
    que.push_back({x, i});
  }

  sort(que.begin(), que.end());

  int l = 1, r = 1e6 + 2, m, lastL = -1;
  for (auto [x, id] : que) {
    if (lastL != -1) {
      l = lastL;
      r = 1e6 + 2;
    }
    while (l <= r) {
      m = (l + r) / 2;
      if (check(m, x)) {
        res[id] = m;
        lastL = m;
        l = m + 1;
      } else {
        r = m - 1;
      }
    }
  }
  for (int i = 0; i < q; i++) {
    cout << res[i] << " ";
  }
}
