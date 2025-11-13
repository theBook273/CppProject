#include <bits/stdc++.h>
#include <cstdio>

using namespace std;

const int MAXN = 2 * 1e5 + 5;

int guest[MAXN];

signed main() {
  cin.tie()->sync_with_stdio(0);

  freopen("XEBU.INP", "r", stdin);
  freopen("XEBU.OUT", "w", stdout);

  int n;
  cin >> n;
  for (int l, r, i = 0; i < n; i++) {
    cin >> l >> r;
    guest[l]++;
    guest[r]--;
  }
  int tong = 0, res = 0;
  for (int i = 1; i <= MAXN; i++) {
    tong += guest[i];
    res = max(tong, res);
  }
  cout << res;
}
