#include <bits/stdc++.h>
#define int unsigned long long

using namespace std;

void solve() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  int tong = 0;
  for (auto &i : a) {
    cin >> i;
    tong += __builtin_popcount(i);
  }
  int temp;
  for (int i = 0; i < 60; i++) {
    temp = (1LL << i);
    for (auto &id : a) {
      if (!(id & temp) && temp <= k) {
        tong++;
        k -= temp;
      }
    }
  }
  cout << tong << "\n";
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
