#include <bits/stdc++.h>
#define int unsigned long long

using namespace std;

void solve() {
  int n, m, q;
  cin >> n >> m >> q;
  vector<int> a(m);
  for (auto &i : a) {
    cin >> i;
  }
  cin >> q;
  sort(a.begin(), a.end());
  if (a[0] < q && q < a[1]) {
    cout << (a[1] - a[0]) / 2;
  } else if (q > a[1]) {
    cout << n - a[1];
  } else {
    cout << a[0] - 1;
  }
  cout << "\n";
}

signed main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
