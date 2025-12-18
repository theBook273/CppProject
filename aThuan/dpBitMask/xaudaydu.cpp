#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 25;

vector<int> a(N + 1);
int n;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    int mask = 0;
    for (char c : s) {
      mask |= (1 << (c - 'a'));
    }
    a[i] = mask;
  }

  unordered_map<int, int> dp, dp2;
  // dp.reserve(1 << 20);
  dp[0] = 1;

  for (int i = 0; i < n; i++) {
    int bit = a[i];
    dp2 = dp;
    for (auto &p : dp) {
      int newmask = p.first | bit;
      dp2[newmask] += p.second;
    }
    dp.swap(dp2);
  }

  int full = (1 << 26) - 1;
  cout << dp[full];
}
