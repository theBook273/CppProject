#include <bits/stdc++.h>
using namespace std;
int main() {
  freopen("TEST.INP", "r", stdin);
  freopen("TEST.OUT", "w", stdout);
  int a;
  int b;
  int c;
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a >> b >> c;
    if (a == b + c or b == a + c or c == a + b) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
}
