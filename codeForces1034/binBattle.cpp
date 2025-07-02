#include <bits/stdc++.h>

using namespace std;

signed main() {
  string ans[] = {"Bob\n", "Alice\n"};

  long long t;
  cin >> t;
  while (t--) {
    bool flag = 0;
    long long n, k;
    cin >> n >> k;

    vector<char> temp(n);
    vector<long long> a;

    for (char &i : temp) {
      cin >> i;
      a.push_back(i - '0');
    }

    long long tong = 0;

    for (auto i : a) {
      tong += i;
    }

    if (tong <= k) {
      cout << ans[1];
      continue;
    }

    if (n % 2 != 0) {
      cout << ans[(k > ((n - 1) / 2))];
    } else {
      cout << ans[(k >= ((n + 2) / 2))];
    }
  }
}
