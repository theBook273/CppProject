#include <bits/stdc++.h>
#define int long long

using namespace std;

int divCnt(int x) {
  int dem = 0;
  for (int i = 1; i * i <= x; i++) {
    if (x % i == 0) {
      dem++;
      if (x / i != i) {
        dem++;
      }
    }
  }
  return dem;
}

int n, res = 0;

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(nullptr);

  freopen("FOURDIV.INP", "r", stdin);
  freopen("FOURDIVTRAU.OUT", "w", stdout);

  cin >> n;
  for (int i = 6; i <= n; i++) {
    if (divCnt(i) == 4) {
      res++;
      // cout << i << "\n";
    }
  }

  cout << res;
}
