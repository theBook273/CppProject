#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  deque<int> q;
  for (auto &i : a) {
    cin >> i;
    q.push_back(i);
  }
  int dem = 0;
  while (!q.empty()) {
    if (dem % 2 == 0) {
      if (q.back() > q.front()) {
        cout << "R";
        q.pop_back();
      } else {
        cout << "L";
        q.pop_front();
      }
    } else {
      if (q.back() < q.front()) {
        cout << "R";
        q.pop_back();
      } else {
        cout << "L";
        q.pop_front();
      }
    }
    dem++;
  }
  cout << "\n";
}

signed main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
