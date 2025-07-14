#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

signed main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &i : a)
    cin >> i;
  vector<int> dp(n, 1);
  vector<int> jump(n, -1);
  for (int i = n - 2; i >= 0; i--) {
    for (int j = i + 1; j < n; j++) {
      if (a[i] <= a[j]) {
        if (dp[i] < dp[j] + 1) {
          dp[i] = dp[j] + 1;
          jump[i] = j;
        }
      }
    }
  }
  int start = max_element(dp.begin(), dp.end()) - dp.begin();
  while (start != -1) {
    cout << a[start] << " ";
    start = jump[start];
  }
}
