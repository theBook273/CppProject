#include <bits/stdc++.h>
#include <cctype>
#include <cstdio>

using namespace std;

signed main() {
  cin.tie()->sync_with_stdio(0);
  freopen("SBD.INP", "r", stdin);
  freopen("SBD.OUT", "w", stdout);
  string s;
  cin >> s;

  if (!('A' <= s[0] && s[0] <= 'Z')) {
    cout << 1;
  } else if (!('A' <= s[1] && s[1] <= 'Z')) {
    cout << 2;
  } else if (s[2] != '-') {
    cout << 3;
  } else if (!isdigit(s[3])) {
    cout << 4;
  } else if (!isdigit(s[4])) {
    cout << 5;
  } else if (!isdigit(s[5])) {
    cout << 6;
  } else if (s[6] != '.') {
    cout << 7;
  } else if (!isdigit(s[7])) {
    cout << 8;
  } else if (!isdigit(s[8])) {
    cout << 9;
  } else if (s.size() >= 10) {
    cout << 10;
  } else {
    cout << 0;
  }
}
