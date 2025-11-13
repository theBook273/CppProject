#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n;
  cin >> n;
  string s;
  map<int, int> cnt;
  cin >> s;
  for (auto i : s) {
    cnt[(i - '0')]++;
  }
  int dem1 = 0;
  if (cnt[1] > 0) {
    dem1 = (cnt[1] - 1) * cnt[1];
  }
  if (cnt[0] > 0) {
    dem1 += (cnt[0] * (cnt[1] + 1));
  }
  cout << dem1 << "\n";
}

signed main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
