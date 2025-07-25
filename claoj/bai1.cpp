#include <bits/stdc++.h>
#define int unsigned long long

using namespace std;

signed main() {
  cin.tie()->sync_with_stdio(0);
  int x, y, z;
  cin >> x >> y >> z;
  int hieu = x - y;
  int a = (z + hieu) / 2;
  int c = (z - hieu) / 2;
  int b = y - c;
  cout << a << " " << b << " " << c;
}
