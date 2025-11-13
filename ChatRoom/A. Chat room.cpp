#include <bits/stdc++.h>

using namespace std;

signed main() {
  string s;
  cin >> s;

  string track = "hello";
  int dem = 0;

  for (int i = 0; i < s.size(); i++) {
    if (s[i] == track[dem]) {
      dem++;
    }
  }

  cout << ((dem == track.size()) ? "YES" : "NO");
}
