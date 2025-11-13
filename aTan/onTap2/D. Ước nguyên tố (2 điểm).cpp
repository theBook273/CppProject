#include <bits/stdc++.h>
#include <cstdio>

using namespace std;

const int MAXN = 1e6 + 5;

bool prime[MAXN];
int dem[MAXN], a[MAXN];
vector<int> primeNum;

signed main() {
  cin.tie()->sync_with_stdio(0);

  freopen("PRIME.INP", "r", stdin);
  freopen("PRIME.OUT", "w", stdout);

  memset(prime, 1, sizeof(prime));

  prime[0] = prime[1] = 0;
  for (int i = 2; i <= MAXN; i++) {
    if (prime[i]) {
      primeNum.push_back(i);
      for (int j = 2; j * i <= MAXN; j++) {
        prime[i * j] = 0;
      }
    }
  }

  int n, uocNT = 0, res = 0;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    dem[i] = 0;
    for (auto j : primeNum) {
      if (j > a[i]) {
        break;
      }
      if (a[i] % j == 0 && prime[j]) {
        dem[i]++;
      }
    }
    if (uocNT < dem[i]) {
      uocNT = dem[i];
      res = a[i];
    }
  }
  cout << res;
}
