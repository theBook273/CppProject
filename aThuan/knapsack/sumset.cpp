#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 1e6;

int n, s = 0;
vector<int> a;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n;
  a.resize(n);
  for (auto &i : a) {
    cin >> i;
    s += i;
  }

  bitset<N + 1> dp;
  dp[0] = 1;
  for (int i : a) {
    dp |= (dp << i);
  }

  cout << dp.count() - 1 << "\n";
}
