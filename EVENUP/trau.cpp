#include <bits/stdc++.h>
using namespace std;
int main() {
  freopen("test.inp", "r", stdin);
  freopen("trau.out", "w", stdout);

  int a[100005], c[100005];
  vector<long int> k;
  long long n, m;
  m = 0;
  bool b[100005];
  cin >> n;
  for (int i = 0; i < n; i++) {
    b[i] = true;
  }
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    k.push_back(a[i]);
  }
  for (int i = 0; i < (n - 1); i++) {
    if (a[i] % 2 == 0 and a[i + 1] % 2 != 0) {
      b[i] = true;
      c[i] = a[i] + a[i + 1];
    } else if (a[i] % 2 != 0 and a[i + 1] % 2 == 0) {
      b[i] = true;
      c[i] = a[i] + a[i + 1];
    } else {
      b[i] = false;
    }
    for (int i = 0; i < (n - 1); i++) {
      if (b[i] == true) {
        if (c[i] > m) {
          m = c[i];
        }
      }
    }
  }
  if (m == 0) {
    cout << "-1";
  } else {
    cout << m;
  }
}
