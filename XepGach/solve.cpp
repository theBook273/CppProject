#include <bits/stdc++.h>

using namespace std;

signed main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &i : a)
    cin >> i;
  sort(a.begin(), a.end(), greater<int>());
  int tong = 1;
  int cung = a[0];
  for (int i = 0; i < n; i++) {
    cung--;
    tong++;
    cung = min(cung, a[i]);
    if (cung == 0)
      break;
  }
  cout << min(n, tong) << "\n";
}
