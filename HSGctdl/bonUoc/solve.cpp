#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAXN(1e7 + 5);
vector<bool> prime(MAXN, 1);
vector<int> primeNum;
int n;

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(nullptr);

  freopen("FOURDIV.INP", "r", stdin);
  freopen("FOURDIV.OUT", "w", stdout);

  prime[0] = prime[1] = 0;
  for (int i = 2; i <= MAXN; i++) {
    if (prime[i]) {
      primeNum.push_back(i);
      for (int j = i + i; j <= MAXN; j += i) {
        prime[j] = 0;
      }
    }
  }

  cin >> n;

  int pos = upper_bound(primeNum.begin(), primeNum.end(), n) - primeNum.begin();

  int res(0);
  for (auto i : primeNum) {
    if (i * i * i > n) {
      break;
    }
    res++;
  }

  for (int i = 0; i < primeNum.size(); i++) {
    int p = primeNum[i];
    int limit = n / p;

    int j = upper_bound(primeNum.begin() + i + 1, primeNum.end(), limit) -
            primeNum.begin();

    res += j - (i + 1);
  }

  cout << res;
}
