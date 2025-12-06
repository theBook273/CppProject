#include <bits/stdc++.h>
#define int long long

using namespace std;

struct node {
  int id, x, y;
  bool operator<(const node &other) { return x < other.x; }
};

const int N = 1e5 + 5;
const int oo = 1e9;

int n;

vector<int> adj[N];

int dis[N], low[N], subSz[N];
int timer = 0;

int comp[N];
int compSz[N];
int currComp = 0;

int ans = oo;

map<int, vector<node>> X, Y;
set<pair<int, int>> edgeUsed;

void process(map<int, vector<node>> &MP) {
  for (auto &entry : MP) {
    auto &vec = entry.second;
    sort(vec.begin(), vec.end());

    multiset<pair<int, int>> active;

    for (auto &item : vec) {
      int id = item.id;
      int start = item.x;
      int end = item.y;

      while (!active.empty()) {
        auto it = active.begin();
        if (it->first < start) {
          active.erase(it);
        } else {
          break;
        }
      }

      for (auto &p : active) {
        int a = p.second, b = id;
        if (a > b) {
          swap(a, b);
        }
        if (!edgeUsed.count({a, b})) {
          edgeUsed.insert({a, b});
          adj[a].push_back(b);
          adj[b].push_back(a);
        }
      }

      active.insert({end, id});
    }
  }
}

int dfsCount(int u) {
  comp[u] = currComp;
  int cnt = 1;

  for (int v : adj[u]) {
    if (!comp[v]) {
      cnt += dfsCount(v);
    }
  }
  return cnt;
}

void tarjan(int u, int parent, int compSize) {
  dis[u] = low[u] = ++timer;
  subSz[u] = 1;

  for (int v : adj[u]) {
    if (v == parent) {
      continue;
    }

    if (dis[v]) {
      low[u] = min(low[u], dis[v]);
    } else {
      tarjan(v, u, compSize);
      low[u] = min(low[u], low[v]);
      subSz[u] += subSz[v];

      if (low[v] >= dis[u]) {
        int left = subSz[v];
        int right = compSize - left;
        ans = min(ans, abs(left - right));
      }
    }
  }
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n;

  for (int i = 1; i <= n; i++) {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    swap(y1, y2);

    X[x1].push_back({i, y1, y2});
    X[x2].push_back({i, y1, y2});
    Y[y1].push_back({i, x1, x2});
    Y[y2].push_back({i, x1, x2});
  }

  process(X);
  process(Y);

  for (int i = 1; i <= n; i++) {
    if (comp[i]) {
      currComp++;
      int csize = dfsCount(i);
      compSz[currComp] = csize;
    }
  }

  for (int i = 1; i <= n; i++) {
    if (!dis[i]) {
      int compo = comp[i];
      tarjan(i, -1, compSz[compo]);
    }
  }

  cout << (ans == oo ? -1 : ans);
}
