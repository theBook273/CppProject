#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    int maxn = 0, minn = 1e9;
    for (int i = 0; i < n; i++) {
      int a;
      cin >> a;
      maxn = max(maxn, a);
      minn = min(minn, a);
    }

    if (k >= maxn) {
      cout << k - minn;
    } else if (k <= minn) {
      cout << maxn - k;
    } else {
      int toleft = maxn - k;
      int toright = k - minn;
      cout << toleft + toright + min(toleft, toright);
    }
    cout << "\n";
  }
}
