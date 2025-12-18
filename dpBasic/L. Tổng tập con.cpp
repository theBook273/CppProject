#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 1e5;

vector<bool> dp(N + 5, 0);

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  dp[0] = 1;
  for (int x, i = 1; i <= n; i++) {
    cin >> x;
    for (int s = N; s >= x; s--) {
      if (dp[s] || dp[s - x]) {
        dp[s] = 1;
      }
    }
  }

  cout << accumulate(dp.begin(), dp.end(), -1) << "\n";

  for (int i = 1; i <= N; i++) {
    if (dp[i]) {
      cout << i << " ";
    }
  }
}
