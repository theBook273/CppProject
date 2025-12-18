#include <bits/stdc++.h>
#define int long long

using namespace std;

const int oo = 1e18;
const int N = 100;

int n, w, weight[N + 5], val[N + 5];

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> w;
  for (int i = 1; i <= n; i++) {
    cin >> weight[i] >> val[i];
  }

  vector<int> dp(w + 1, -oo);
  dp[0] = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = weight[i]; j <= w; j++) {
      dp[j] = max(dp[j], dp[j - weight[i]] + val[i]);
    }
  }

  cout << *max_element(dp.begin(), dp.end());
}
