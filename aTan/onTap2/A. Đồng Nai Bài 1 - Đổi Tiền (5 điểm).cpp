#include <bits/stdc++.h>

using namespace std;

signed main() {
  cin.tie()->sync_with_stdio(0);
  long double n;
  cin >> n;
  cout << ceil(n / 50000) * 50000 - n;
}
