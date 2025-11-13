#include <bits/stdc++.h>

using namespace std;

signed main() {
  cin.tie()->sync_with_stdio(0);
  vector<int> G, L;
  int t;
  cin >> t;
  char type;
  int num;
  while (t--) {
    cin >> type >> num;
    if (type == 'G') {
      G.push_back(num);
    } else {
      L.push_back(num);
    }
  }

  sort(G.begin(), G.end());
  sort(L.begin(), L.end());

  if (G.empty() || L.empty() || G.back() <= L.front()) {
    cout << 0;
    return 0;
  }

  int j = 0, ans = INT_MAX;
  for (int i = 0; i <= G.size(); i++) {
    int gVal;
    if (i == G.size()) {
      gVal = INT_MAX;
    } else {
      gVal = G[i];
    }

    while (j < L.size() && L[j] < gVal) {
      j++;
    }
    ans = min(ans, i + j);
  }

  cout << ans;
}
