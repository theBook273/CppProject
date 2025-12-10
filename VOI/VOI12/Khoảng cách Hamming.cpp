#include <bits/stdc++.h>

using namespace std;

const int oo = 1e9;

int n, m, k, res = oo;
vector<string> si;
string base;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> m >> k;
  cin >> base;
  base += base;

  for (int i = 0; i < (int)(base.size() - m + 1); i++) {
    string temp = base.substr(i, m);
    si.push_back(temp);
  }

  while (k--) {
    string temp;
    cin >> temp;
    for (auto &x : si) {
      int tong = 0;
      for (int i = 0; i < m; i++) {
        tong += (temp[i] != x[i]);
      }
      res = min(res, tong);
    }
  }

  cout << res;
}
