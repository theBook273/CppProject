#include <bits/stdc++.h>

using namespace std;

string queAns[] = {"No\n", "Yes\n"};

void solve() {
  string a, b;
  cin >> a >> b;
  if (a == b) {
    cout << queAns[1];
    return;
  }

  bool head = 0;
  deque<char> q;
  for (auto &i : b) {
    q.push_back(i);
  }

  while (q.size() > a.size()) {
    if (head == 0) {
      if (q.front() == 'B') {
        head = 1;
      }
      q.pop_front();
    } else {
      if (q.back() == 'B') {
        head = 0;
      }
      q.pop_back();
    }
  }

  b.clear();
  if (head == 0) {
    for (auto &i : q) {
      b.push_back(i);
    }
  } else {
    while (!q.empty()) {
      b.push_back(q.back());
      q.pop_back();
    }
  }

  cout << queAns[b == a];
}

signed main() {
  cin.tie()->sync_with_stdio(0);
  for (int i = 0; i < 3; i++) {
    solve();
  }
}
