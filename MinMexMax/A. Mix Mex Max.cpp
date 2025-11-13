#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n;
  cin >> n;
  int a[n];
  map<int, int> mp;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    mp[a[i]]++;
  }
  if ((mp.size() == 1 || (mp.size() == 2 && mp.count(-1))) && !mp.count(0)) {
    cout << "YES \n";
  } else {
    cout << "NO\n";
  }
}

signed main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
