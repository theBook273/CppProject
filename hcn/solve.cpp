#include <bits/stdc++.h>

using namespace std;

double dientich(int a, int b, int c, int d) {
  double temp1 = abs(a - c);
  double temp2 = abs(b - d);

  return temp1 * temp2;
}

signed main() {
  int n;
  cin >> n;

  vector<pair<pair<int, int>, pair<int, int>>> a(n);

  for (auto &[bot, top] : a)
    cin >> bot.first >> bot.second >> top.first >> top.second;
}
