#include <bits/stdc++.h>
#define int long long

using namespace std;

struct Edge {
  int from, to;
};

vector<Edge> edge;

signed main() {
  cin.tie()->sync_with_stdio(0);

  // freopen("graph.inp", "r", stdin);
  // freopen("graph.out", "w", stdout);

  int d, k, now;
  cin >> d >> k;

  if (d > 2) {
    int head = 1, tail = d - 1;
    for (int i = 1; i < d - 1; i++) {
      edge.push_back({i, i + 1});
    }

    now = tail + 1;
    int left = 1, right = k;
    for (int i = 1; i * i <= k; i++) {
      if (k % i == 0) {
        int a = i;
        int b = k / i;
        if (abs(a - b) < abs(left - right)) {
          left = a, right = b;
        }
      }
    }

    for (int i = 0; i < left; i++) {
      edge.push_back({now, head});
      now++;
    }

    for (int i = 0; i < right; i++) {
      edge.push_back({now, tail});
      now++;
    }
  } else {
    now = 3;
    edge.push_back({1, 2});
    int s = 1;
    while (s * (s - 1) / 2 < k) {
      edge.push_back({1, now});
      now++;
      s++;
    }
  }

  cout << now - 1 << " " << edge.size() << "\n";
  for (auto [u, v] : edge) {
    if (u > v) {
      swap(u, v);
    }
    cout << u << " " << v << "\n";
  }
}
