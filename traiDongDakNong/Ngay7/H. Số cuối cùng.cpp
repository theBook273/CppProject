#include <bits/stdc++.h>
#define int unsigned long long

using namespace std;

int sizeNum(int x) {
  double dem = log10(x);
  dem = floor(dem);
  dem++;
  return dem;
}

signed main() {
  cin.tie()->sync_with_stdio(0);

  freopen("digits.inp", "r", stdin);
  freopen("digits.out", "w", stdout);

  int start, step, stop;
  cin >> start >> step >> stop;
  int sumDi = 0;
  for (; sumDi < stop; start += step) {
    if (sumDi + sizeNum(start) >= stop) {
      break;
    }
    sumDi += sizeNum(start);
  }

  int digit = stop - sumDi;
  if (digit == sizeNum(start)) {
    cout << start;
  } else {
    string s = to_string(start);
    for (int i = 0; i < digit; i++) {
      cout << s[i];
    }
  }
}
