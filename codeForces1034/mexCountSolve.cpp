#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  set<int> excl;
  map<int, int> mp;
  for (int i = 0; i <= n; ++i) {
    excl.insert(i);
  }
  for (int &i : a) {
    cin >> i;
    mp[i]++;
    excl.erase(i);
  }
  int mex = *excl.begin();
  map<int, vector<int>> freq;
  for (auto [i, j] : mp)
    freq[j].push_back(i);
  set<int> cnt;
  cnt.insert(mex);
  for (int k = 0; k <= n; k++) {
    cnt.erase(n - (k - 1));
    for (int i : freq[k]) {
      if (i <= min(mex, n - k)) {
        cnt.insert(i);
      }
    }
    cout << cnt.size() << " ";
  }
  cout << "\n";
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--)
    solve();
}
