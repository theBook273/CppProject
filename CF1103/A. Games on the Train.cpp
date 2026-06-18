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

  cout << *max_element(a.begin(), a.end()) + 1 -
              *min_element(a.begin(), a.end())
       << "\n";
}

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
