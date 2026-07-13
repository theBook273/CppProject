#include <bits/stdc++.h>

using namespace std;

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  string s;
  cin >> s;

  if (s.size() & 1) {
    cout << "No";
  } else {
    stack<char> st;
    for (auto &i : s) {
      if (!st.empty() && st.top() == i) {
        st.pop();
      } else {
        st.push(i);
      }
    }
    if (!st.empty()) {
      cout << "No";
    } else {
      cout << "Yes";
    }
  }
}
