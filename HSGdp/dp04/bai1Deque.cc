#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main() {
  cin.tie()->sync_with_stdio(0);

  freopen("SMGIFT.INP", "r", stdin);
  freopen("SMGIFT.OUT", "w", stdout);

  int n, k;
  cin >> n >> k;
  vector<int> a(n + 1), pre(n + 1), dp(n + 1, LLONG_MIN);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    pre[i] = pre[i - 1] + a[i];
  }

  deque<int> q;
  dp[0] = 0;
  q.push_back(0);
  int ans = 0;

  for (int i = 1; i <= n; i++) {
    while (!q.empty() && q.front() < i - k - 1) {
      q.pop_front();
    }

    if (i <= k) {
      dp[i] = pre[i];
    }

    if (!q.empty()) {
      dp[i] = max(dp[i], dp[q.front()] + pre[i] - pre[q.front() + 1]);
    }

    while (!q.empty() &&
           dp[q.back()] - pre[q.back() + 1] <= dp[i] - pre[i + 1]) {
      q.pop_back();
    }
    q.push_back(i);

    ans = max(ans, dp[i]);
  }
  cout << ans;
}
