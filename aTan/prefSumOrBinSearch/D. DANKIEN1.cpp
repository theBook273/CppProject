#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main() {
  cin.tie()->sync_with_stdio(0);
  int n, k, tong = 0;
  cin >> n >> k;
  for (int temp, i = 0; i < n; i++) {
    cin >> temp;
    tong += abs(k - temp);
  }
  cout << tong;
}
