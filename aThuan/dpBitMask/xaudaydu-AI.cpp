#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<int> a(n);

  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    int mask = 0;
    for (char c : s)
      mask |= 1 << (c - 'a');
    a[i] = mask;
  }

  unordered_map<int, long long> dp, dp2;
  dp.reserve(1 << 20);
  dp[0] = 1;

  for (int bm : a) {
    dp2 = dp;
    for (auto &p : dp) {
      int newmask = p.first | bm;
      dp2[newmask] += p.second;
    }
    dp.swap(dp2);
  }

  int full = (1 << 26) - 1;
  cout << dp[full];
}
