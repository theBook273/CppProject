#include <bits/stdc++.h>

using namespace std;

signed main() {
  set<int> se = {2, 4, 51, 6};
  cout << *++se.begin();
  se.erase(se.begin());
  cout << *se.begin();
}
