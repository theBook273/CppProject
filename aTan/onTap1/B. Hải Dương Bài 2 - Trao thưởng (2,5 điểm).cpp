#include <bits/stdc++.h>
#define int unsigned long long

using namespace std;

signed main() {
  cin.tie()->sync_with_stdio(0);
  int n, d;
  cin >> n >> d;
  cout << n * (2 + (n - 1) * d) / 2;
}
