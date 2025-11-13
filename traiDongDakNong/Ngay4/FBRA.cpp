#include <bits/stdc++.h>
#include <vector>
#define int long long

using namespace std;

const int MOD = 1000000007LL;

bool isOpen(char a, char needOpen) { return (a == needOpen) || (a == '?'); }
bool isClose(char a, char needClose) { return (a == needClose) || (a == '?'); }

signed main() {
  cin.tie()->sync_with_stdio(0);
  freopen("test.inp", "r", stdin);
  freopen("testChuan.out", "w", stdout);
  string s;
  cin >> s;
  int n = (int)s.size();
  if (n % 2 == 1) {
    cout << 0 << "\n";
    return 0;
  }

  vector<vector<int>> dp(n, vector<int>(n, 0));
  vector<pair<char, char>> types = {{'[', ']'}, {'(', ')'}, {'{', '}'}};
  for (int len = 2; len <= n; len++) {
    if (len % 2 == 1) {
      continue;
    }

    for (int l = 0; l + len - 1 < n; l++) {
      int r = l + len - 1;
      int ways = 0;

      for (int k = l + 1; k <= r; k += 2) {
        int leftInside = 1;
        if (k - 1 >= l + 1) {
          leftInside = dp[l + 1][k - 1];
        }

        int rightPart = 1;
        if (k + 1 <= r) {
          rightPart = dp[k + 1][r];
        }

        int addTypes = 0;
        for (auto &tp : types) {
          if (isOpen(s[l], tp.first) && isClose(s[k], tp.second)) {
            addTypes = (addTypes + 1) % MOD;
          }
        }

        if (addTypes != 0) {
          ways = (ways + addTypes * (leftInside * rightPart) % MOD) % MOD;
        }
      }
      dp[l][r] = ways;
    }
  }

  cout << dp[0][n - 1] % MOD << "\n";
}
