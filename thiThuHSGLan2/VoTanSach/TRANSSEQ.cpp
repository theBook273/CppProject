#include <bits/stdc++.h>
#define int long long

using namespace std;

int k, q, s, n, l, r, v;

mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
int randint(int l, int r) { return uniform_int_distribution<int>(l, r)(rng); }

namespace sub12 {

void main() {
  vector<int> now = {s};
  while (n--) {
    vector<int> next;
    for (int i = 0; i < now.size(); i++) {
      if (now[i] + 1 > k) {
        for (int j = k; j >= 0; j--) {
          next.push_back(j);
        }
      } else {
        next.push_back(now[i] + 1);
      }
    }
    now.swap(next);
  }

  int res = 0;
  for (int i = l - 1; i < r; i++) {
    res += (now[i] == v);
  }

  cout << res << "\n";

  // for (int i : now) {
  //   cout << i << " ";
  // }
  // cout << "\n";
}

} // namespace sub12

signed main() {
  cin.tie()->sync_with_stdio(0);
  srand(time(0));

  freopen("TRANSSEQ.INP", "r", stdin);
  freopen("TRANSSEQ.OUT", "w", stdout);

  cin >> k >> q;
  while (q--) {
    cin >> s >> n >> l >> r >> v;
    if (n <= 30) {
      sub12::main();
    } else {
      cout << randint(l, r) << "\n";
    }
  }
}
