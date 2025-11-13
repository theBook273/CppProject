#include <bits/stdc++.h>

using namespace std;

signed main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &i : a)
    cin >> i;
  int cnt = 0;
  stack<int> st;
  for (auto i : a) {
    while (!st.empty() && st.top() > i) {
      st.pop();
    }
    if ((st.empty() || st.top() < i) && i > 0) {
      st.push(a[i]);
      cnt++;
    }
  }
  cout << cnt << "\n";
}
