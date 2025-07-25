#include <bits/stdc++.h>

using namespace std;

signed main() {
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto &i : a)
      cin >> i;
    sort(a.begin(), a.end());
    for (auto i : a)
      cout << i << " ";
    cout << "\n";
  }
}
