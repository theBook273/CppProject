#include <bits/stdc++.h>

using namespace std;

const int MAXN = 5 * 1e5 + 5;

vector<int> adj[MAXN];
int tin[MAXN], tout[MAXN], pos[MAXN];
int timer;

void setup(int u, int p) {
  tin[u] = ++timer;
  pos[timer] = u;
  for (auto v : adj[u]) {
    if (v != p) {
      setup(v, u);
    }
  }
  tout[u] = timer;
}

signed main() { cin.tie()->sync_with_stdio(0); }
