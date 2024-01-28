#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin >> t;

  while (t--) {
    long long l, r, d, k, total = 0;

    cin >> l >> r >> d >> k;

    while (l <= r) {
      total += abs(l - k);
      l += d;
    }

    cout << total << endl;
  }
}
