#include <bits/stdc++.h>

using namespace std;

int step[] = {1, 2, 3};
int pos = 0, tong = 0;
int n, m;

void check() {
  if (pos == n) {
    tong++;
    return;
  }
  for (auto i : step) {
    if (pos + i <= n) {
      pos += i;
      check();
      pos -= i;
    }
  }
}

signed main() {
  cin.tie()->sync_with_stdio(0);
  cin >> n >> m;
  for (int i = 1; i <= 10; i++) {
    n = i;
    tong = 0;
    check();
    cout << tong << "\n";
  }
}
