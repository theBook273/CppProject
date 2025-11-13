#include <bits/stdc++.h>
#define int long long

using namespace std;

void solve() {
  int k, a, b, x, y;
  cin >> k >> a >> b >> x >> y;
  pair<int, int> t1 = {a, x};
  pair<int, int> t2 = {b, y};
  if (t1.second > t2.second) {
    swap(t1, t2);
  }
  int tong = max(0LL, (k - t1.first + 1) / t1.second);
  k -= (tong * t1.second);
  if (k >= t1.first) {
    k -= t1.second;
    tong++;
  }
  if (k > t2.first) {
    tong += ((k - t2.first + 1) / t2.second);
    k -= t2.second * ((k - t2.first + 1) / t2.second);
  } else if (k == t2.first) {
    tong++;
    k = 0;
  }
  if (k >= t2.first) {
    k -= t2.second;
    tong++;
  }
  cout << tong << "\n";
}

signed main() {
  cin.tie()->sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
