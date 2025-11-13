#include <bits/stdc++.h>

using namespace std;

void solve() {
  stack<char> st;
  int n;
  cin >> n;
  vector<char> s(n);
  for (auto &i : s) {
    cin >> i;
  }
  for (int i = 0; i < n; i++) {
    if (!st.empty() && st.top() == '(' && s[i] == ')') {
      st.pop();
    } else {
      st.push(s[i]);
    }
  }
  cout << st.size() / 2 << "\n";
}

signed main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
