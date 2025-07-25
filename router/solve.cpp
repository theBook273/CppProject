#include <bits/stdc++.h>

using namespace std;

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  int n;
  cin >> n;
  vector<int> a(n + 1);
  a[1] = -1;
  for (int i = 2; i <= n; i++) {
    cin >> a[i];
  }
  stack<int> st;
  st.push(n);
  int next = a[n];
  for (int i = n; i >= 1; i--) {
    if (i == next) {
      st.push(i);
      next = a[i];
    }
  }
  while (!st.empty()) {
    cout << st.top() << " ";
    st.pop();
  }
}
