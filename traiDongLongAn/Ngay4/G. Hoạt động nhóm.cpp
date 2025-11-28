#include <bits/stdc++.h>

using namespace std;

const int N = 300;

set<int> know[N + 1], nothing[N + 1];
vector<pair<int, int>> friendline;

int gen(int x) {
  set<int> group;

  int isfriend = 3, isnothing = 3;
  for (int i : know[x]) {
    for (int j : know[x]) {
      if (i != j) {
      }
    }
  }

  return group.size();
}

void solve() {
  int n, m;
  cin >> n >> m;

  set<int> know[n + 1], nothing[n + 1];
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (i != j) {
        nothing[i].insert(j);
      }
    }
  }

  for (int u, v, i = 0; i < m; i++) {
    cin >> u >> v;
    friendline.push_back({u, v});
    nothing[u].erase(v);
    nothing[v].erase(u);
    know[v].insert(u);
    know[u].insert(v);
  }

  // for (int i = 1; i <= n; i++) {
  //   cout << i << ":\n";
  //   cout << "know: ";
  //   for (auto x : know[i]) {
  //     cout << x << " ";
  //   }
  //   cout << "\n nothing: ";
  //   for (auto x : nothing[i]) {
  //     cout << x << " ";
  //   }
  //   cout << endl << endl;
  // }
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
