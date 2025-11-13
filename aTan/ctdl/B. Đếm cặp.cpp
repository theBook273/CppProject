#include <bits/stdc++.h>

using namespace std;

map<int, pair<int, vector<int>>> mp;
vector<int> a;
int n, k, tong = 0;

signed main() {
  cin.tie()->sync_with_stdio(0);
  cin >> n >> k;

  for (int temp, i = 0; i < n; i++) {
    cin >> temp;
    a.push_back(temp);
    mp[temp].first++;
    mp[temp].second.push_back(i);
  }

  for (int i = 0; i < n; i++) {
    int temp = k - a[i];
    if (mp.count(temp)) {
      for (int dem : mp[temp].second) {
        if (dem > i) {
          tong++;
        }
      }
    }
  }

  cout << tong;
}
