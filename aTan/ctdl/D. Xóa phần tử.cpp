#include <bits/stdc++.h>
#define int long long

using namespace std;

map<int, vector<int>> mp;

signed main() {
  cin.tie()->sync_with_stdio(0);
  int n;
  cin >> n;
  for (int temp, i = 0; i < n; i++) {
    cin >> temp;
    mp[temp].push_back(i);
  }

  if (mp.size() > 2) {
    cout << 0;
    return 0;
  }

  int temp = INT_MAX;
  for (auto [i, j] : mp) {
    temp = min(temp, (int)j.size());
  }

  if (temp != 1 && mp.size() > 1) {
    cout << 0;
    return 0;
  }

  for (auto [i, j] : mp) {
    if (j.size() == temp) {
      cout << j.front() + 1;
    }
  }
}
