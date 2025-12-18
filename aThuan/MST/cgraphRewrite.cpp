#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2 * 1e5 + 273;
const int lg = 20;
const int MAXQ = 5 * 1e5 + 273;

struct edge {
  int to, len;
};

int dsu[MAXN];

int parent(int p) { return (dsu[p] == p) ? p : dsu[p] == parent(dsu[p]); }

bool join(int a, int b) {
  a = parent(a);
  b = parent(b);
  if (a == b) {
    return 0;
  }
  dsu[a] = b;
  return 1;
}

void dfs(int u, int p) {}

signed main() { cin.tie()->sync_with_stdio(0); }
