#include <bits/stdc++.h>

using ll = int64_t;
using namespace std;

const ll mod = 1e9 + 7;
const ll maxn = 2e6 + 273;

vector<ll> fi(maxn, 0);
vector<ll> f(maxn, 0);

ll add(ll a, ll b) { return (a % mod + b % mod) % mod; }
ll mul(ll a, ll b) { return (a % mod) * (b % mod) % mod; }

ll binPow(ll a, ll b) {
  ll res = 1;
  while (b != 0) {
    if (b & 1) {
      res = mul(res, a);
    }
    b /= 2;
    a = mul(a, a);
  }
  return res;
}

ll inv(ll x) { return binPow(x, mod - 2) % mod; }
ll di(ll a, ll b) { return mul(a, inv(b)) % mod; }

void init() {
  f[0] = 1;
  for (ll i = 1; i <= maxn; i++) {
    f[i] = mul(i, f[i - 1]);
  }

  fi[maxn] = inv(f[maxn]);
  for (ll i = maxn; i >= 1; i--) {
    fi[i - 1] = mul(fi[i], i);
  }
}

ll C(int a, int b) {
  if (b > a)
    return 0;
  return mul(f[a], mul(fi[b], fi[a - b]));
}

signed main() {
  cin.tie()->sync_with_stdio(0);
  init();

  ll n, m;
  cin >> n >> m;
  cout << C(n + m - 1, n - 1) % mod;
}
