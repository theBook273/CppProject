#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAXN(1e6 + 5);
const int MOD(1e9 + 7);

vector<bool> prime(MAXN, 1);
vector<int> primeNum;
int l, r, tong(0);

int sz(int &x) {
  double res = log10(x);
  return floor(res) + 1;
}

int extract(int &x, int &where) { return (x % where); }

int f(int &p1, int &p2) {
  int num = 10;
  while (sz(num) - 1 < sz(p1)) {
    num *= 10;
  }
  int res = p2;
  while (extract(res, num) != p1) {
    res += p2;
  }
  return res;
}

int add(int x, int y) { return ((x % MOD) + (y % MOD)) % MOD; }

signed main() {
  cin.tie()->sync_with_stdio(0);
  cout.tie()->sync_with_stdio(0);

  freopen("SUFPRI.INP", "r", stdin);
  freopen("SUFPRI.OUT", "w", stdout);

  cin >> l >> r;

  prime[0] = prime[1] = 0;
  for (int i = 2; i <= MAXN; i++) {
    if (prime[i]) {
      if (l <= i && i <= r) {
        primeNum.push_back(i);
      }
      for (int j = i * 2; j <= MAXN; j += i) {
        prime[j] = 0;
      }
    }
  }

  for (int i = 0; i < primeNum.size() - 1; i++) {
    int now = f(primeNum[i], primeNum[i + 1]);
    // cout << primeNum[i] << " " << primeNum[i + 1] << " " << now << " "
    //      << now / primeNum[i + 1] << " " << prime[now / primeNum[i + 1]]
    //      << "\n";
    tong = add(tong, now % MOD);
  }
  cout << tong;
}
