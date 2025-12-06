#include <bits/stdc++.h>
#define int long long

using namespace std;

struct shipping {
  int from, to;
  bool operator<(const shipping &other) { return to < other.to; }
};

const int oo = 1e18;

int n, m;
vector<shipping> a;
vector<shipping> except;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  freopen("GIAOHANG.INP", "r", stdin);
  freopen("GIAOHANG.OUT", "w", stdout);
  cin >> n >> m;
  a.resize(n);
  for (auto &[from, to] : a) {
    cin >> from >> to;
    if (from > to) {
      except.push_back({from, to});
    }
  }
  if (!except.empty()) {
    int res = 0;
    sort(except.begin(), except.end());
    int start = 0;
    int mini = except[0].to, maxi = except[0].from;
    for (auto &[from, to] : except) {
      if ((mini <= from && from <= maxi) || (mini <= to && to <= maxi)) {
        mini = min({mini, from, to});
        maxi = max({maxi, from, to});
      } else {
        res += (maxi - start + (maxi - mini));
        start = mini;
        mini = to;
        maxi = from;
      }
    }
    res += (maxi - start + (maxi - mini) + m - mini);
    cout << res;
  } else {
    cout << m;
  }
}
