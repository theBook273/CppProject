#include <bits/stdc++.h>

using namespace std;

signed main() {
  double a, b, c;
  cin >> a >> b >> c;
  int tong = a + b + c;
  double avg = (a + b + c) / 3.0;
  cout << tong << " ";
  cout << fixed << setprecision(2) << avg;
}
