#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MOD = 14062008;

int n, k;

signed main() {
  cin.tie()->sync_with_stdio(0);
  cin >> n >> k;
  unordered_map<int, int> mp;
  for (int temp, i = 0; i < k; i++) {
    cin >> temp;
    mp[temp]++;
  }

  vector<int> dp(n + 1);
  dp[0] = 0;
  dp[1] = 1;
  for (int i = 2; i <= n; i++) {
    if (mp.count(i)) {
      dp[i] = 0;
      continue;
    }
    dp[i] = (dp[i - 1] + dp[i - 2]) % MOD;
  }

  cout << dp[n];
}
