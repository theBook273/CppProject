#include <bits/stdc++.h>

using namespace std;

const int MOD = 998244353;

unordered_map<int, int> mp;
int tong = 0, res = 0;
int n, m;

void solve() {
  if (tong == n) {
    res++;
    return;
  }
  for (int i = 2; i <= 3; i++) {
    if (tong + i <= n && !mp.count(tong + i)) {
      tong += i;
      solve();
      tong -= i;
    }
  }
}

signed main() {
  cin.tie()->sync_with_stdio(0);

  freopen("BACTHANG.inp", "r", stdin);
  freopen("BACTHANG.out", "w", stdout);

  cin >> n >> m;
  for (int temp, i = 0; i < m; i++) {
    cin >> temp;
    mp[temp]++;
  }

  solve();
  cout << res % MOD;
}
