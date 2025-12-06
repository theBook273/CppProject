#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 1e6;
const int MOD = 1e9 + 7;

int add(int a, int b) { return ((a % MOD) + (b % MOD)) % MOD; }

vector<int> dp(N + 5);
int t, n;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  dp[1] = 1;
  dp[2] = 2;

  for (int i = 3; i <= N; i++) {
    dp[i] = add(dp[i - 1], dp[i - 2]);
  }

  cin >> t;
  while (t--) {
    cin >> n;
    cout << dp[n] << "\n";
  }
}
