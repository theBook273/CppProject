#include <bits/stdc++.h>

using namespace std;

signed main() {
  int t;
  cin >> t;

  while (t--) {
    int dem[4] = {0, 0, 0, 0};

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
      dem[i % 4]++;
    }

    if (dem[1] == dem[2] && dem[3] == dem[0])
      cout << "Bob\n";
    else
      cout << "Alice\n";
  }
}
