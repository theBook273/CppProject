#include <bits/stdc++.h>

using namespace std;

mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

int rd(int l, int r) { return uniform_int_distribution<int>(l, r)(rng); }

signed main() {
  set<int> se = {2, 4, 51, 6};
  cout << *++se.begin();
  se.erase(se.begin());
  cout << *se.begin();
}
