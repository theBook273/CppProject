#include <bits/stdc++.h>

using namespace std;
//
// vector<int> temp;
//
// void trying(int s, int tong, int id, vector<int> a) {
//   if (tong == s && id == a.size() - 1) {
//     for (auto i : temp) {
//       cout << i << " ";
//     }
//     cout << "\n";
//     return;
//   }
//
//   if (id + 1 < a.size() && tong + a[id + 1] <= s) {
//     temp.push_back(a[id + 1]);
//     tong += a[id + 1];
//     trying(s, tong, id + 1, a);
//     tong -= a[id + 1];
//     temp.pop_back();
//   }
//   if (id - 1 >= 0 && tong + a[id - 1] <= s) {
//     temp.push_back(a[id - 1]);
//     tong += a[id - 1];
//     trying(s, tong, id - 1, a);
//     tong -= a[id - 1];
//     temp.pop_back();
//   }
// }
//
void solve() {
  int n, s;
  cin >> n >> s;
  vector<int> a(n);
  unordered_map<int, int> mp;
  int tong = 0;
  for (auto &i : a) {
    cin >> i;
    mp[i]++;
    tong += i;
  }
  // temp.push_back(a[0]);
  // trying(s, a[0], 0, a);
  // cout << "\n";
  if (s == tong || s - tong >= 2) {
    cout << -1 << "\n";
  } else {
    while (mp[0]--) {
      cout << 0 << " ";
    }
    while (mp[2]--) {
      cout << 2 << " ";
    }
    while (mp[1]--) {
      cout << 1 << " ";
    }
    cout << "\n";
  }
}

signed main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
