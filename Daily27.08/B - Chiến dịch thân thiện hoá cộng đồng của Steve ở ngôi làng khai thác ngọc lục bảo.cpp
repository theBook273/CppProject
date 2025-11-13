#include <bits/stdc++.h>
#include <functional>
#define int long long

using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &i : a) {
    cin >> i;
  }
  sort(a.begin(), a.end(), greater<int>());
  int tong = 0;
  for (int i = 0; i < (n / 2) * 2 - 1; i += 2) {
    tong += a[i];
    a[i] = a[i + 1] = 0;
  }
  for (auto i : a) {
    if (i != 0) {
      tong += i;
    }
  }
  cout << tong << "\n";
}

signed main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
