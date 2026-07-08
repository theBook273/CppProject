#include <bits/stdc++.h>

using namespace std;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  string a[n];
  for (auto &i : a) {
    cin >> i;
  }

  unordered_set<string> st;

  for (int i = n - 1; i >= 0; i--) {
    if (!st.count(a[i])) {
      st.insert(a[i]);
      cout << a[i] << "\n";
    }
  }
}
