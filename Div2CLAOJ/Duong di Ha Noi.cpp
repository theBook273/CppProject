#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  int n;
  cin >> n;
  int x, y;
  x = y = -1;
  for (int i = n; i >= 0; i--) {
    int temp = (n - 2 * i - 1);
    if (temp % 9 == 0 && temp >= 0) {
      x = i;
      y = (temp) / 9;
    }
  }
  if (x != -1) {
    cout << 4 * x + 81 * y;
  } else {
    cout << x;
  }
}
