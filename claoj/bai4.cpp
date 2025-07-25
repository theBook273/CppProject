#include <bits/stdc++.h>

using namespace std;

void update(int x, int u, vector<int> a[], vector<int> &sta) {
  for (auto i : a[u]) {
    sta[i] = x;
    if (!a[i].empty())
      update(x, i, a, sta);
  }
}

signed main() {
  int n, q;
  cin >> n >> q;
  vector<int> a[n + 1], sta(n + 1);
  for (int i = 1; i <= n; i++) {
    int k;
    cin >> k;
    while (k != 0 && k--) {
      int temp;
      cin >> temp;
      a[i].push_back(temp);
    }
    sta[i] = 1;
  }
  // for (auto i : a) {
  //   for (auto j : i)
  //     cout << j << " ";
  //   cout << "\n";
  // }
  while (q--) {
    int type, u;
    cin >> type >> u;
    sta[u] = type;
    update(type, u, a, sta);
  }
  for (int i = 1; i <= n; i++) {
    cout << sta[i] << " ";
  }
  cout << "\n";
}
