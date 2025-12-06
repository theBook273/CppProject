#include <bits/stdc++.h>
#define int long long

using namespace std;

const int oo = 1e18;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;

  vector<pair<int, int>> films(n);
  for (auto &[u, v] : films) {
    cin >> u >> v;
  }

  sort(films.begin(), films.end(), [](pair<int, int> &a, pair<int, int> &b) {
    return a.second < b.second;
  });

  int last = -oo, res = 0;
  for (auto &[u, v] : films) {
    if (u >= last) {
      res++;
      last = v;
    }
  }
  cout << res;
}
