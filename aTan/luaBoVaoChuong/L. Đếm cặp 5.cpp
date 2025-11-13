#include <bits/stdc++.h>

using namespace std;

signed main() {
  cin.tie()->sync_with_stdio(0);
  int n, MOD;
  cin >> n >> MOD;

  vector<int> dem(MOD + 1, 0);

  for (int temp, i = 0; i < n; i++) {
    cin >> temp;
    dem[temp % MOD]++;
  }

  int tong = 0;

  for (auto i : dem) {
    tong += (i * (i - 1)) / 2;
  }

  cout << tong;
}
