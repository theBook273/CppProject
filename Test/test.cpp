#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("FINDDANTE.INP", "r", stdin);
  freopen("FINDDANTE.OUT", "w", stdout);

  map<int, int> mp;

  int n;
  while (cin >> n) {
    mp[n]++;
  }

  for (auto i : mp) {
    if (i.second % 2 == 1) {
      cout << i.first;
    }
  }
}
