#include <bits/stdc++.h>

using namespace std;

char x, y;
int lim = 8;
vector<string> store;
string s;
int demx, demy;

void gen() {
  if (s.size() == lim) {
    store.push_back(s);
    return;
  }
  if (demx < lim / 2) {
    demx++;
    s.push_back(x);
    gen();
    demx--;
    s.pop_back();
  }
  if (demy < lim / 2) {
    demy++;
    s.push_back(y);
    gen();
    demy--;
    s.pop_back();
  }
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  x = '1';
  y = '2';

  gen();
  // sort(store.begin(), store.end());
  for (auto i : store) {
    cout << i << "\n";
  }
}
