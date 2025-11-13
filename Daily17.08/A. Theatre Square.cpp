#include <bits/stdc++.h>
#define int unsigned long long

using namespace std;

signed main() {
  double n, m, a;
  cin >> n >> m >> a;
  int l = ceil(n / a), w = ceil(m / a);
  int res = l * w;
  cout << res;
}
