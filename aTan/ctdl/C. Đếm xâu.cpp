#include <bits/stdc++.h>

using namespace std;

map<string, int> mp;
string temp;
int n;

signed main() {
  cin.tie()->sync_with_stdio(0);
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> temp;
    mp[temp]++;
  }

  for (auto [i, j] : mp) {
    cout << i << " " << j << "\n";
  }
}
