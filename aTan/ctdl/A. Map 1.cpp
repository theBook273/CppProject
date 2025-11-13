#include <bits/stdc++.h>

using namespace std;

int n, q;
map<int, int> mp;

signed main() {
  cin.tie()->sync_with_stdio(0);
  cin >> n;
  for (int temp, i = 0; i < n; i++) {
    cin >> temp;
    mp[temp]++;
  }

  cin >> q;
  int ask;
  while (q--) {
    cin >> ask;
    cout << mp[ask] << "\n";
  }
}
