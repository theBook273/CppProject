#include <bits/stdc++.h>

using namespace std;

unordered_map<int, int> mp;

signed main() {
  cin.tie()->sync_with_stdio(0);
  int n;
  cin >> n;

  for (int temp, i = 0; i < n; i++) {
    cin >> temp;
    mp[temp]++;
    if (mp[temp] > 1) {
      cout << "NO";
      return 0;
    }
  }

  cout << "YES";
}
