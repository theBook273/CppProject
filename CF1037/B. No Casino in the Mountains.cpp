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
    vector<int> nextRainDay(n + 1);
    nextRainDay[n - 1] = ((a[n - 1] == 1) ? n - 1 : n);
    for (int i = n - 2; i >= 0; i--) {
      if (a[i] == 1) {
        nextRainDay[i] = i;
      } else if (a[i + 1] == 1) {
        nextRainDay[i] = i + 1;
      } else {
        nextRainDay[i] = nextRainDay[i + 1];
      }
    }
    int tong = 0;
    // for (auto i : nextRainDay)
    //   cout << i << " ";
    // cout << "\n";
    for (int i = 0; i < n; i++) {
      if (a[i] == 0 && nextRainDay[i] > i + k - 1) {
        tong++;
        i = i + k;
      }
    }
    cout << tong << "\n";
  }
}
