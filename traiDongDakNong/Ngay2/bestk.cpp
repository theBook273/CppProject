#include <bits/stdc++.h>

using namespace std;

signed main() {
  cin.tie()->sync_with_stdio(0);
  int c, n, k;
  cin >> c >> n >> k;

  if (k == 1) {
    vector<int> a(n + 1), dp(n + 1, 1), trace(n + 1);
    vector<bool> mark(n + 1, 0);
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }

    for (int i = 1; i <= n; i++) {
      for (int j = 1; j < i; j++) {
        if (a[i] > a[j]) {
          if (dp[i] < dp[j] + 1) {
            dp[i] = dp[j] + 1;
            trace[i] = j;
          }
        }
      }
    }

    pair<int, int> anchor = {0, 0};

    for (int i = 1; i <= n; i++) {
      if (anchor.second < dp[i]) {
        anchor = {i, dp[i]};
      }
    }

    int now = anchor.first;
    do {
      mark[now] = 1;
      now = trace[now];
    } while (trace[now] != now);

    int res = 0;
    for (int i = 1; i <= n; i++) {
      if (!mark[i]) {
        for (int j = 0; j <= n; j++) {
          if (a[j] <= a[i] && a[j + 1] >= a[i]) {
            res += (abs(i - (j + 1)));
            break;
          }
        }
      }
    }

    cout << res;
  }
}
