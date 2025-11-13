#include <bits/stdc++.h>
#define int long long

using namespace std;

int n;
vector<int> a, b;
set<int> se;

signed main() {
  cin.tie()->sync_with_stdio(0);

  freopen("sequence.inp", "r", stdin);
  freopen("sequence.out", "w", stdout);

  cin >> n;
  a.resize(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    se.insert(a[i]);
  }

  b.push_back(0);
  for (auto i : se) {
    b.push_back(i);
  }

  vector<int> dp_prev(b.size() + 1), dp_now(b.size() + 1);

  dp_now[1] = abs(a[1] - b[1]);

  for (int j = 2; j < (int)b.size(); j++) {
    dp_now[j] = min(abs(a[1] - b[j]), dp_now[j - 1]);
  }

  dp_prev = dp_now;

  for (int i = 2; i <= n; i++) {
    dp_now[1] = dp_prev[1] + abs(a[i] - b[1]);
    for (int j = 2; j < (int)b.size(); j++) {
      dp_now[j] = min(dp_now[j - 1], dp_prev[j] + abs(a[i] - b[j]));
    }
    dp_prev = dp_now;
  }

  cout << dp_now[b.size() - 1];
}
