#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 2000;

vector<vector<int>> dp(N + 2, vector<int>(N + 2, 0));
vector<vector<string>> trace(N + 2, vector<string>(N + 2, ""));

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  string a, b;
  cin >> a >> b;

  int res = 0;
  string tracing;

  for (int i = 1; i <= (int)a.size(); i++) {
    for (int j = 1; j <= (int)b.size(); j++) {
      if (a[i - 1] == b[j - 1]) {
        dp[i][j] = dp[i - 1][j - 1] + 1;
        trace[i][j] = trace[i - 1][j - 1];
        trace[i][j].push_back(a[i - 1]);
      } else {
        if (dp[i - 1][j] >= dp[i][j - 1]) {
          dp[i][j] = dp[i - 1][j];
          trace[i][j] = trace[i - 1][j];
        } else {
          dp[i][j] = dp[i][j - 1];
          trace[i][j] = trace[i][j - 1];
        }
      }
      if (res < dp[i][j]) {
        res = dp[i][j];
        tracing = trace[i][j];
      }
    }
  }

  cout << tracing << "\n";
  int cnt = 0;
  for (int i = 0; i < (int)a.size(); i++) {
    if (a[i] == tracing[cnt]) {
      cout << i + 1 << " ";
      cnt++;
      if (cnt == (int)tracing.size()) {
        break;
      }
    }
  }

  cout << "\n";

  cnt = 0;
  for (int i = 0; i < (int)b.size(); i++) {
    if (b[i] == tracing[cnt]) {
      cout << i + 1 << " ";
      cnt++;
      if (cnt == (int)tracing.size()) {
        break;
      }
    }
  }
}
