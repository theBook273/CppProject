#include <bits/stdc++.h>
using namespace std;
long long dp[2][20][180];
int x[20];
long long l, r;
long long s;

long long f(int idx, bool smaller, int sum);
long long G(long long X);

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> l >> r;
    --l;
    long long sum = 0;
    for (s = 1; s <= 171; ++s) {
      sum += G(r / s) - G(l / s);
    }
    cout << sum << '\n';
  }
  return 0;
}
long long f(int idx, bool smaller, int sum) {
  if (idx < 0)
    return sum == s;
  long long &memo = dp[smaller][idx][sum];
  if (memo != -1)
    return memo;
  int lim = smaller ? 9 : x[idx];
  memo = 0;
  for (int digit = 0; digit <= lim; ++digit) {
    memo += f(idx - 1, smaller || (digit < lim), sum + digit);
  }
  return memo;
}
long long G(long long X) {
  if (X <= 0)
    return 0;
  int n = 0;
  x[n] = 0;
  for (; X > 0; ++n) {
    x[n] = X % 10;
    X /= 10;
  }
  memset(dp, -1, sizeof(dp));
  return f(n - 1, 0, 0);
}
