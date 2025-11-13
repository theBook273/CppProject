#include <bits/stdc++.h>
#define int unsigned long long

using namespace std;

bool check(int x) {
  int temp = sqrtl(x);
  return temp * temp == x;
}

int a, b, res = 0;

signed main() {
  cin.tie()->sync_with_stdio(0);
  cin >> a >> b;
  if (!check(a)) {
    res = 1;
  }
  int canh = sqrtl(a);
  int tar = ceil(sqrtl(b));
  res += canh - tar;
  cout << res;
}
