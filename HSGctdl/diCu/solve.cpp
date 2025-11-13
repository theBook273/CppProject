#include <bits/stdc++.h>

using namespace std;

int n, h, k;
int tong = 0, dem = 0, res = 0;
vector<int> trace;

void solve() {
  if (tong == h && dem == n) {
    for (auto i : trace) {
      cout << i << " ";
    }
    cout << "\n";
    res++;
    return;
  }

  for (int i = -k; i <= k; i++) {
    if (0 <= tong + i && tong + i <= h && dem + 1 <= n && i != 0) {
      trace.push_back(i);
      dem++;
      tong += i;
      solve();
      trace.pop_back();
      tong -= i;
      dem--;
    }
  }
}

signed main() {
  cin.tie()->sync_with_stdio(0);
  cin >> n >> h >> k;

  solve();

  cout << res;
}
