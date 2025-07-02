#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;

    vector<int> a(n);

    vector<int> minT(n), maxP(n);

    for (int &i : a)
      cin >> i;

    minT[0] = a[0];
    maxP[n - 1] = a[n - 1];

    for (int i = 1; i < n; i++) {
      minT[i] = min(minT[i - 1], a[i]);
    }

    for (int i = n - 2; i >= 0; i--) {
      maxP[i] = max(maxP[i + 1], a[i]);
    }

    for (int i = 0; i < n; i++) {
      cout << (a[i] == minT[i] || a[i] == maxP[i]);
    }
    cout << "\n";
  }
}
