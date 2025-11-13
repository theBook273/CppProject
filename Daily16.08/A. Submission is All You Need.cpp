#include <bits/stdc++.h>

using namespace std;

int mex(int a, int b) {
  while (a <= b) {
    a++;
  }
  return a;
}

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  int thuanTong = 0;
  for (auto &i : a) {
    cin >> i;
    thuanTong += (i + (i == 0));
  }
  cout << thuanTong << "\n";
}

signed main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
