// #include <bits/stdc++.h>
// #define int long long
//
// using namespace std;
//
// const int N = 3e5;
// const int lg = 20;
//
// struct Edge {
//   int from, to, key, id;
// };
//
// int n, m, start, tar, tplt = 0, timer = 0;
// vector<vector<int>> parent(N, vector<int>(lg + 1, 0));
// vector<int> in, dis, depth, id, low, scc;
// stack<int> st;
// vector<Edge> edge;
// vector<pair<int, int>> comp[N + 1], adj[N + 1];
//
// void tarjan(int u, int lastId) {
//   id[u] = low[u] = ++timer;
//   st.push(u);
//   for (auto [v, i] : adj[u]) {
//     if (i == lastId) {
//       continue;
//     }
//     if (!id[v]) {
//       tarjan(v, i);
//     }
//     low[u] = min(low[u], low[v]);
//   }
//
//   if (low[u] == id[u]) {
//     int v;
//     tplt++;
//     do {
//       v = st.top();
//       scc[v] = tplt;
//       st.pop();
//     } while (v != u);
//   }
// }
//
// void dfsSetup(int u, int p) {
//   for (auto [v, w] : comp[u]) {
//     if (v == p) {
//       continue;
//     }
//     parent[v][0] = u;
//     dis[v] = dis[u] + w;
//     depth[v] = depth[u] + 1;
//     dfsSetup(v, u);
//   }
// }
//
// void init() {
//   dfsSetup(1, -1);
//   for (int j = 1; j <= lg; j++) {
//     for (int i = 1; i <= n; i++) {
//       int mid = parent[i][j - 1];
//       parent[i][j] = parent[mid][j - 1];
//     }
//   }
// }
//
// int lca(int u, int v) {
//   if (depth[u] < depth[v]) {
//     swap(u, v);
//   }
//
//   int x = depth[u] - depth[v];
//   for (int i = lg; i >= 0; i--) {
//     if (x & (1 << i)) {
//       u = parent[u][i];
//       x -= (1 << i);
//     }
//   }
//
//   if (u == v) {
//     return u;
//   }
//
//   for (int i = lg; i >= 0; i--) {
//     if (parent[u][i] != parent[v][i]) {
//       u = parent[u][i];
//       v = parent[v][i];
//     }
//   }
//
//   return parent[u][0];
// }
//
// int disBet(int u, int v) {
//   return dis[u] + dis[v] + in[u] + in[v] - 2 * dis[lca(u, v)];
// }
//
// signed main() {
//   ios::sync_with_stdio(false);
//   cin.tie(nullptr);
//
//   cin >> n >> m;
//
//   id.resize(n + 1, 0);
//   low.resize(n + 1, 0);
//   scc.resize(n + 1, 0);
//   depth.resize(n + 1, 0);
//   dis.resize(n + 1, 0);
//   in.resize(n + 1, 0);
//
//   for (int u, v, x, i = 0; i < m; i++) {
//     cin >> u >> v >> x;
//     adj[u].push_back({v, i});
//     adj[v].push_back({u, i});
//     edge.push_back({u, v, x, i});
//   }
//
//   cin >> start >> tar;
//
//   for (int i = 1; i <= n; i++) {
//     if (!id[i]) {
//       tarjan(i, -1);
//     }
//   }
//
//   if (scc[start] == scc[tar]) {
//     for (auto [u, v, x, i] : edge) {
//       u = scc[u];
//       v = scc[v];
//
//       if (x == 1) {
//         if (scc[start] == scc[tar] && u == v && v == scc[start]) {
//           cout << "YES";
//           return 0;
//         }
//       }
//     }
//     cout << "NO";
//     return 0;
//   }
//
//   for (auto [u, v, x, i] : edge) {
//     u = scc[u];
//     v = scc[v];
//
//     if (u == v) {
//       in[u] += x;
//     }
//
//     if (v != u) {
//       comp[u].push_back({v, x});
//       comp[v].push_back({u, x});
//     }
//   }
//
//   start = scc[start];
//   tar = scc[tar];
//
//   init();
//
//   if (disBet(start, tar)) {
//     cout << "YES";
//   } else {
//     cout << "NO";
//   }
// }
//
#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  if (!(cin >> n >> m))
    return 0;
  struct E {
    int u, v, z;
  };
  vector<E> edges;
  edges.reserve(m);

  vector<vector<pair<int, int>>> g(n + 1); // (to, edgeId)
  for (int i = 0; i < m; ++i) {
    int u, v, z;
    cin >> u >> v >> z;
    edges.push_back({u, v, z});
    g[u].push_back({v, i});
    g[v].push_back({u, i});
  }
  int a, b;
  cin >> a >> b;

  // 1) Tarjan bridges (tin/low)
  vector<int> tin(n + 1, 0), low(n + 1, 0);
  vector<char> is_bridge(m, 0);
  int timer = 0;
  function<void(int, int)> dfs = [&](int u, int pe) {
    tin[u] = low[u] = ++timer;
    for (auto [v, id] : g[u]) {
      if (id == pe)
        continue;
      if (!tin[v]) {
        dfs(v, id);
        low[u] = min(low[u], low[v]);
        if (low[v] > tin[u]) {
          is_bridge[id] = 1;
        }
      } else {
        // back edge
        low[u] = min(low[u], tin[v]);
      }
    }
  };
  for (int i = 1; i <= n; ++i)
    if (!tin[i])
      dfs(i, -1);

  // 2) Build components by skipping bridge edges
  vector<int> comp(n + 1, 0);
  int compCnt = 0;
  for (int i = 1; i <= n; ++i) {
    if (comp[i])
      continue;
    compCnt++;
    // iterative stack to avoid recursion
    stack<int> st;
    st.push(i);
    comp[i] = compCnt;
    while (!st.empty()) {
      int u = st.top();
      st.pop();
      for (auto [v, id] : g[u]) {
        if (comp[v] == 0 && !is_bridge[id]) {
          comp[v] = compCnt;
          st.push(v);
        }
      }
    }
  }

  int ca = comp[a], cb = comp[b];
  // If same component: answer YES iff there exists at least one internal edge
  // with z==1 in that component We'll compute comp_has_key below; but we can
  // early handle trivial case after computing comp_has_key.

  // 3) Build bridge-tree and mark component internal keys
  vector<char> comp_has_key(compCnt + 1, 0);
  vector<vector<pair<int, int>>> tree(compCnt +
                                      1); // (neighborComp, bridge_has_key)
  for (int id = 0; id < m; ++id) {
    int u = edges[id].u, v = edges[id].v, z = edges[id].z;
    int cu = comp[u], cv = comp[v];
    if (cu == cv) {
      if (z == 1)
        comp_has_key[cu] = 1;
    } else {
      // it's a bridge edge in original graph (note: if not marked bridge but
      // cu!=cv, it must be bridge) since we formed components by skipping
      // bridges, any edge connecting two different components is a bridge
      // However there might be multiple edges between same cu-cv (parallel
      // edges) but then none are bridges. Here safe to add; if multiple, they
      // won't be bridges all at once — but construction guarantees edges
      // between comps are original bridges.
      tree[cu].push_back({cv, z});
      tree[cv].push_back({cu, z});
    }
  }

  if (ca == cb) {
    cout << (comp_has_key[ca] ? "YES" : "NO") << '\n';
    return 0;
  }

  // 4) BFS on tree from ca to cb, store parent and through-edge-key flag
  vector<int> parent(compCnt + 1, -1);
  vector<int> parentEdgeKey(compCnt + 1, 0);
  queue<int> q;
  q.push(ca);
  parent[ca] = 0; // mark visited, root's parent 0
  bool found = false;
  while (!q.empty() && !found) {
    int u = q.front();
    q.pop();
    for (auto [v, z] : tree[u]) {
      if (parent[v] == -1) {
        parent[v] = u;
        parentEdgeKey[v] = z; // z==1 if that bridge has key
        if (v == cb) {
          found = true;
          break;
        }
        q.push(v);
      }
    }
  }
  if (parent[cb] == -1) {
    // disconnected in bridge-tree (shouldn't happen if original graph
    // connected, but handle)
    cout << "NO\n";
    return 0;
  }
  // reconstruct path ca <- ... <- cb and check
  int cur = cb;
  bool ok = false;
  while (cur != 0) {
    if (comp_has_key[cur]) {
      ok = true;
      break;
    }
    if (parentEdgeKey[cur] == 1) {
      ok = true;
      break;
    }
    cur = parent[cur];
  }
  cout << (ok ? "YES" : "NO") << '\n';
  return 0;
}
