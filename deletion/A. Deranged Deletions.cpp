#include <bits/stdc++.h>

using namespace std;

string ans[] = {"NO", "YES"};

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &i : a)
    cin >> i;
  vector<int> temp = a;
  sort(temp.begin(), temp.end());
  cout << ans[(temp != a)] << "\n";
  if (temp != a) {
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        if (a[i] > a[j]) {
          cout << 2 << "\n";
          cout << a[i] << " " << a[j] << "\n";
          return;
        }
      }
    }
  }
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
