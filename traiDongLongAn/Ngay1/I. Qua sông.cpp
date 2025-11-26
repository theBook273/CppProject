#include <bits/stdc++.h>
#define int long long

using namespace std;

vector<int> dis;
int n, m, k;

bool check(int x) {
  int tong = 0;
  int dem = 1;
  for (int i = 0; i < n; i++) {
    if (dis[i] > x) {
      return 0;
    }
    if (tong + dis[i] > x) {
      dem++;
      tong = dis[i];
    } else {
      tong += dis[i];
    }
  }
  return dem <= k;
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("river.inp", "r", stdin);
  freopen("river.out", "w", stdout);

  cin >> n >> m >> k;

  for (int i = 0; i < n; i++) {
    dis.push_back(1 + ((i % m) * (i % m)) % m);
  }

  int l = 1, r = 1e18, res = 0;
  while (l <= r) {
    int mid((l + r) / 2);
    if (check(mid)) {
      res = mid;
      r = mid - 1;
    } else {
      l = mid + 1;
    }
  }

  cout << res;
}
