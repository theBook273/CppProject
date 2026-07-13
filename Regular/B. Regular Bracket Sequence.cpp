#include <bits/stdc++.h>

using namespace std;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int tong = 0;

  string s;
  cin >> s;

  stack<char> st;
  for (auto &i : s) {
    if (i == '(') {
      st.push(i);
    } else if (!st.empty()) {
      st.pop();
      tong += 2;
    }
  }

  cout << tong;
}
