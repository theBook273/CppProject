#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, w;
  cin >> n >> w;

  vector<int> we(n), va(n);

  for (int i = 0; i < n; i++) {
    cin >> we[i] >> va[i];
  }

  vector<int> dp(w + 1, 0);

  for (int i = 0; i < n; i++) {
    for (int j = w; j >= we[i]; j--) {
      dp[j] = max(dp[j], dp[j - we[i]] + va[i]);
    }
  }

  cout << *max_element(dp.begin(), dp.end());
}
