#include <bits/stdc++.h>
#define int unsigned long long

using namespace std;

signed main() {
  cin.tie()->sync_with_stdio(0);
  int a, b, c;
  cin >> a >> b >> c;
  cout << a * b - (c * a + c * b - c * c);
}
