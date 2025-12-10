#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 3000;

string a, b;
vector<vector<int>> dp(N + 2, vector<int>(N + 2, 0));

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> a >> b;

  int res = 0;

  for (int i = 1; i <= (int)a.size(); i++) {
    for (int j = 1; j <= (int)b.size(); j++) {
      if (a[i - 1] == b[j - 1]) {
        dp[i][j] = dp[i - 1][j - 1] + 1;
      } else {
        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
      }
      res = max(res, dp[i][j]);
    }
  }

  cout << res;
}
