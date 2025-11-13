#include <bits/stdc++.h>
#include <cstdio>

using namespace std;

signed main() {
  cin.tie()->sync_with_stdio(0);
  freopen("prep.out", "w", stdout);
  for (int h = 0; h < 24; h++) {
    for (int m = 0; m < 60; m++) {
      for (int s = 0; s < 60; s++) {
        if (h < 10)
          cout << "0";
        cout << h << ":";

        if (m < 10)
          cout << "0";
        cout << m << ":";

        if (s < 10)
          cout << "0";
        cout << s << "\n";
      }
    }
  }
}
