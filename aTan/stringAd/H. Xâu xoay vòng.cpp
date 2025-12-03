#include <bits/stdc++.h>

using namespace std;

void rotate(string &s) {
  deque<char> q;
  for (auto &i : s) {
    q.push_back(i);
  }

  char temp = q.back();
  q.pop_back();
  q.push_front(temp);

  s.clear();

  for (auto &i : q) {
    s.push_back(i);
  }
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  string a, b;
  cin >> a >> b;
  if (a.size() != b.size()) {
    cout << "NO";
    return 0;
  }

  for (int i = 0; i < (int)a.size(); i++) {
    rotate(a);
    if (a == b) {
      cout << "YES";
      return 0;
    }
  }

  cout << "NO";
}
