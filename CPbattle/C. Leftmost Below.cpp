#include <bits/stdc++.h>
#define int long long

using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &i : a) {
    cin >> i;
  }
  vector<int> b = a;
  sort(a.begin(), a.end(), greater<int>());
  for (int i = 0; i < n; i++) {
    if (a[i] != b[i]) {
      cout << "NO\n";
      return;
    }
  }
  cout << "YES\n";
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
