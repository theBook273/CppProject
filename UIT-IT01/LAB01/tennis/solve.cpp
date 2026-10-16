#include <bits/stdc++.h>

using namespace std;

signed main() {
  int a, b;
  cin >> a >> b;
  if (a < b) {
    swap(a, b);
  }
  if (a == 7 && b >= 5 && b < 7) {
    cout << 1;
    return 0;
  }
  if (a == 6 && b < 5) {
    cout << 1;
    return 0;
  }
  cout << 0;
}
