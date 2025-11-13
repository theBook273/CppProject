#include <bits/stdc++.h>

using namespace std;

signed main() {
  cin.tie()->sync_with_stdio(0);
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  for (int &i : a) {
    cin >> i;
  }

  int res = 0;

  sort(a.begin(), a.end());
  for (int i = 0; i < n; i++) {
    if (a[i] > m) {
      break;
    }

    int l = i + 1, r = n - 1;
    while (l < r) {
      int sum = a[i] + a[l] + a[r];
      if (sum > m) {
        r--;
      } else if (sum < m) {
        l++;
      } else {
        l++;
        r--;
        res++;
      }
    }
  }

  cout << res;
}
