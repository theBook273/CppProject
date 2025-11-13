#include <bits/stdc++.h>

using namespace std;

int dsu[1002733];

int parent(int x) {
  if (dsu[x] == x) {
    return x;
  }
  dsu[x] = parent(dsu[x]);
  return dsu[x];
}

void join(int a, int b) {
  a = parent(a);
  b = parent(b);
  if (a != b) {
    dsu[a] = b;
  }
}

signed main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    dsu[i] = i;
  }
  for (int i = 1; i <= n; i++) {
    int temp;
    cin >> temp;
    join(temp, i);
  }

  unordered_set<int> se;
  for (int i = 1; i <= n; i++) {
    se.insert(parent(dsu[i]));
  }

  cout << se.size();
}
