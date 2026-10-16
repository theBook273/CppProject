#include <bits/stdc++.h>

using namespace std;

signed main() {
  double p, r, t;
  cin >> p >> r >> t;
  double interest = p * r * t / 100;
  double total = p + interest;
  cout << fixed << setprecision(2) << interest << " " << total;
}
