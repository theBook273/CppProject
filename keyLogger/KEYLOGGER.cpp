#include <bits/stdc++.h>
#define int long long

using namespace std;

string decode(string s) {
  deque<char> bef, aft;
  for (auto &i : s) {
    if (i == '<') {
      if (!bef.empty()) {
        char temp = bef.back();
        bef.pop_back();
        aft.push_front(temp);
      }
    } else if (i == '>') {
      if (!aft.empty()) {
        char temp = aft.front();
        aft.pop_front();
        bef.push_back(temp);
      }
    } else if (i == '-') {
      if (!bef.empty()) {
        bef.pop_back();
      }
    } else {
      bef.push_back(i);
    }
  }

  string res;
  for (auto &i : bef) {
    res.push_back(i);
  }
  for (auto &i : aft) {
    res.push_back(i);
  }

  return res;
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  string recv;
  cin >> recv;
  cout << decode(recv);

  cin.tie(0);
}
