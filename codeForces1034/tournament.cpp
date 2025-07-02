#include <bits/stdc++.h>

using namespace std;

signed main() {
  long long t;
  cin >> t;

  while (t--) {
    bool flag = 0;
    long long n, j, k;
    cin >> n >> j >> k;

    vector<long long> a(n);

    for (long long &i : a)
      cin >> i;

    if (k > 1) {
      cout << "YES\n";
      continue;
    }

    if (a[j - 1] == *max_element(a.begin(), a.end())) {
      cout << "YES\n";
    } else
      cout << "NO\n";
  }
}
