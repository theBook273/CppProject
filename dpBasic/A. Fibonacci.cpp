#include <bits/stdc++.h>
#define int unsigned long long

using namespace std;

vector<int> fibo(105);

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  fibo[0] = fibo[1] = 1;

  for (int i = 2; i <= 100; i++) {
    fibo[i] = fibo[i - 2] + fibo[i - 1];
  }

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    cout << fibo[n] << "\n";
  }
}
