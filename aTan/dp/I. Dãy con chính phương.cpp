#include <bits/stdc++.h>
#define int long long

using namespace std;

int n;

vector<int> a, dp;

bool check(int x) {
  int temp = sqrt(x);
  return (temp * temp == x);
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n;

  a.resize(n, 0);
  dp.resize(n, 1);

  for (auto &i : a) {
    cin >> i;
  }

  for (int i = 0; i < n; i++) {
    for (int j = max(i - 10, 0LL); j < i; j++) {
      if (a[i] != a[j] && check(abs(a[i] - a[j]))) {
        dp[i] = max(dp[i], dp[j] + 1);
      }
    }
  }

  cout << *max_element(dp.begin(), dp.end());
}
