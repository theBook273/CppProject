#include <bits/stdc++.h>
#define int long long
#define INF 2e9
using namespace std;

int digit[30];
long long dp[30][4]; // dp[i][j] đại diện cho một số i chữ số, với số lượng chữ
                     // số không phải 0 nhỏ hơn hoặc bằng 3-j

int dfs(
    int pos, bool limit,
    int non_zero_number) { // số lượng chữ số khác 0 từ vị trí cao nhất đến pos
  if (non_zero_number == 4)
    return 0; // phải đặt trước pos==0
  if (pos == 0)
    return 1; // là số đẹp

  if (!limit && dp[pos][non_zero_number] != -1)
    return dp[pos][non_zero_number];

  long long temp = 0;
  int upper_bound = limit ? digit[pos] : 9;
  for (int i = 0; i <= upper_bound; i++) {

    temp +=
        dfs(pos - 1, limit && (i == upper_bound), non_zero_number + (i != 0));
  }
  if (!limit)
    dp[pos][non_zero_number] = temp;
  return temp;
}

long long solve(long long num) { // đếm số đẹp từ 0 đến num
  int k = 0;
  memset(dp, -1, sizeof(dp));
  while (num) {
    digit[++k] = num % 10;
    num /= 10;
  }
  long long c = dfs(k, true, 0);
  return c;
}

signed main() {
  ios::sync_with_stdio(false);

  int t;
  cin >> t;
  while (t--) {
    long long l, r;
    cin >> l >> r;
    cout << solve(r) - solve(l - 1) << endl;
  }

  return 0;
}
