#include <bits/stdc++.h>

using namespace std;

signed main() {
  long long t;
  cin >> t;

  while (t--) {
    long long dem[4] = {0, 0, 0, 0};

    long long n;
    cin >> n;

    for (long long i = 0; i < n; i++) {
      dem[i % 4]++;
    }

    if (dem[1] == dem[2] && dem[3] == dem[0])
      cout << "Bob\n";
    else
      cout << "Alice\n";
  }
}
