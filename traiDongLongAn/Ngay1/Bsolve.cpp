#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second
using namespace std;

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  // freopen("minsum.inp", "r", stdin);
  // freopen("minsum.out", "w", stdout);
  int t;
  cin >> t;
  while (t--) {
    int x, y;
    cin >> x >> y;
    int x1 = x, y1 = y;
    vector<int> prime, prime2;
    int k = max(sqrt(x) + 1, sqrt(y) + 1);
    for (int i = 2; i <= k; i++) {
      if (x % i == 0)
        prime.push_back(i);
      else if (y % i == 0)
        prime.push_back(i);
      while (x % i == 0 && x > 1) {
        x /= i;
      }
      while (y % i == 0 && y > 1) {
        y /= i;
      }
    }
    if (x != 1)
      prime.push_back(x);
    if (y != 1)
      prime.push_back(y);
    for (auto v : prime) {
      if (v == 1)
        continue;
      int dem = 0;
      int a = x1, b = y1;
      while (a % v == 0) {
        a /= v;
        dem = (dem + 1) % 2;
      }
      while (b % v == 0) {
        b /= v;
        dem = (dem + 1) % 2;
      }
      if (dem != 0)
        prime2.push_back(v);
    }
    int ans = x1 + y1;
    for (int mask = 0; mask < (1 << (int)(prime2.size())); mask++) {
      int a = 1, b = 1;
      for (int i = 0; i < prime2.size(); i++)
        if ((mask >> i) & 1)
          a *= prime2[i];
        else
          b *= prime2[i];
      if (a + b < ans) {
        ans = a + b;
        x1 = a;
        y1 = b;
      }
    }
    cout << x1 << " " << y1 << endl;
  }
}
