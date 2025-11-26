#include <bits/stdc++.h>

using namespace std;

string ho(string s) {
  string temp;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] != ' ') {
      temp.push_back(s[i]);
    } else {
      return temp;
    }
  }
  return temp;
}

string ten(string s) {
  string temp;
  for (int i = s.size() - 1; i >= 0; i--) {
    if (s[i] != ' ') {
      temp.push_back(s[i]);
    } else {
      reverse(temp.begin(), temp.end());
      return temp;
    }
  }
  reverse(temp.begin(), temp.end());
  return temp;
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("bff.inp", "r", stdin);
  freopen("bff.out", "w", stdout);

  int n;
  cin >> n;
  vector<string> s;
  for (int i = 0; i <= n; i++) {
    string temp;
    getline(cin, temp);
    s.push_back(temp);
  }

  int tong = 0;

  for (int i = 0; i < s.size(); i++) {
    for (int j = 0; j < s.size(); j++) {
      if (i != j && ho(s[i]) == ten(s[j])) {
        tong++;
      }
    }
  }

  cout << tong;
}
