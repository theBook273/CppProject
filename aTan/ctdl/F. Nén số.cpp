#include <bits/stdc++.h>

using namespace std;

map<int, vector<int>> mp;
vector<int> a;

signed main() {
  cin.tie()->sync_with_stdio(0);
  int n;
  cin >> n;
  a.resize(n);
  for (int temp, i = 0; i < n; i++) {
    cin >> temp;
    mp[temp].push_back(i);
  }

  int cnt = 1;
  for (auto [i, j] : mp) {
    for (auto dem : j) {
      a[dem] = cnt;
    }
    cnt++;
  }

  for (auto i : a) {
    cout << i << " ";
  }
}
