#include <bits/stdc++.h>

using namespace std;

long long cutCake(long long a, long long b, long long c) {
  return (__gcd(a, __gcd(c, b)));
}

signed main() {
  long long a, b, c;
  cin >> a >> b >> c;
  cout << cutCake(a, b, c);
}
