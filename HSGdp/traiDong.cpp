#include <bits/stdc++.h>

using namespace std;

struct toChoose {
  int val, id;

  bool operator<(const toChoose &other) const { return val > other.val; }
};

int n, m;
int act[1273][1273];

signed main() {
  cin.tie()->sync_with_stdio(0);
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> act[i][j];
    }
  }

  vector<toChoose> dp;

  for (int i = 1; i <= n; i++) {
    dp.push_back({act[1][i], i});
  }

  sort(dp.begin(), dp.end());

  for (int day = 2; day <= n; day++) {
    vector<toChoose> temp;
    for (int job = 1; job <= m; job++) {
      if (job == dp[0].id) {
        temp.push_back({act[day][job] + dp[1].val, job});
      } else {
        temp.push_back({act[day][job] + dp[0].val, job});
      }
    }
    sort(temp.begin(), temp.end());
    dp.swap(temp);
  }

  int ans = 0;
  for (auto [i, j] : dp) {
    ans = max(ans, i);
  }

  cout << ans;
}
