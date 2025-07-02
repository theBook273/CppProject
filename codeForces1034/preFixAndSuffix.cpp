#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;

    vector<long long> a(n);

    vector<long long> minT(n), maxP(n);

    for (long long &i : a)
      cin >> i;

    minT[0] = a[0];
    maxP[n - 1] = a[n - 1];

    for (long long i = 1; i < n; i++) {
      minT[i] = min(minT[i - 1], a[i]);
    }

    for (long long i = n - 2; i >= 0; i--) {
      maxP[i] = max(maxP[i + 1], a[i]);
    }

    for (long long i = 0; i < n; i++) {
      cout << (a[i] == minT[i] || a[i] == maxP[i]);
    }
    cout << "\n";
  }
}
