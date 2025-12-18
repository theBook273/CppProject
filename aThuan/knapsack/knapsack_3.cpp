#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 100;

int n, w, quan[N + 5], weight[N + 5], val[N + 5];

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> w;
  for (int i = 1; i <= n; i++) {
    cin >> quan[i] >> weight[i] >> val[i];
  }

  vector<int> dp(w + 1, 0);
  for (int i = 1; i <= n; i++) {
    int cnt = quan[i];
    int base = 1;

    while (cnt > 0) {
      int take = min(base, cnt);
      cnt -= take;
      int ww = weight[i] * take;
      int vv = val[i] * take;

      for (int j = w; j >= ww; j--) {
        dp[j] = max(dp[j], dp[j - ww] + vv);
      }

      base <<= 1;
    }
  }

  cout << *max_element(dp.begin(), dp.end());
}
