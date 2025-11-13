#include <bits/stdc++.h>

using namespace std;

vector<int> a;
int n;

signed main() {
  cin.tie()->sync_with_stdio(0);

  freopen("HOPTAC.INP", "r", stdin);
  freopen("HOPTAC.OUT", "w", stdout);

  cin >> n;
  for (int temp, i = 0; i < n; i++) {
    cin >> temp;
    a.push_back(temp);
  }

  int tong = 0, tongbinh = 0;
  for (auto &i : a) {
    tong += i;
    tongbinh += i * i;
  }
  cout << (tong * tong - tongbinh) / 2;
}
