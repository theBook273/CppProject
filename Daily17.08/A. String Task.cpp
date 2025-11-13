#include <bits/stdc++.h>
#include <cctype>

using namespace std;

map<char, bool> vo = {{'a', 1}, {'o', 1}, {'y', 1},
                      {'e', 1}, {'u', 1}, {'i', 1}};

signed main() {
  string s;
  cin >> s;
  for (int i = 0; i < s.size(); i++) {
    s[i] = tolower(s[i]);
  }
  for (int i = 0; i < s.size(); i++) {
    if (!vo[s[i]]) {
      cout << "." << s[i];
    }
  }
}
