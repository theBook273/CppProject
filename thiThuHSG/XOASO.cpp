#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAXN = 1e6 + 5;

int pre[MAXN], a[MAXN];
int n, tong = 0, res = 0;
string s;

signed main() {
  cin.tie()->sync_with_stdio(0);

  // freopen("XOASO.inp", "r", stdin);
  // freopen("XOASO.out", "w", stdout);

  cin >> s;
  n = s.size();
  for (int i = 0; i < n; i++) {
    a[i] = s[i] - '0';
    tong += a[i];
  }

  pre[0] = a[0];
  for (int i = 1; i < n; i++) {
    pre[i] = pre[i - 1] + a[i];
  }

  res = (tong % 3 == 0);

  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= i; j++) {
      int temp = pre[i] - (j > 0 ? pre[j - 1] : 0);
      if ((tong - temp) % 3 == 0 && !(j == 0 && i == n - 1)) {
        res++;
      }
    }
  }

  cout << res;
}
