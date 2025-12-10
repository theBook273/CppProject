#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 1e5;
const int lim = 20;
const int oo = 1e18;

struct Edge {
    int from, to, len;
    bool operator<(const Edge &other) {
        return len > other.len;
    }
};

int n, m;
vector<int> dsu, depth;
vector<vector<int>> parent(N + 1, vector<int>(lim + 5, 0)),
       mindis(N + 1, vector<int>(lim + 5, 0));
vector<pair<int, int>> adj[N + 5];
vector<Edge> edge, nonLink;

int acs(int x) {
    return ((dsu[x] == x) ? x : dsu[x] = acs(dsu[x]));
}

bool join(int a, int b) {
    a = acs(a);
    b = acs(b);
    if (a != b) {
        dsu[a] = b;
        return 1;
    }
    return 0;
}

void dfsSetup(int u, int p) {
    for (auto &[v, w] : adj[u]) {
        if (v == p) {
            continue;
        }

        depth[v] = depth[u] + 1;
        mindis[v][0] = w;
        parent[v][0] = u;
        dfsSetup(v, u);
    }
}

void init() {
    dfsSetup(1, -1);

    for (int j = 1; j <= lim; j++) {
        for (int i = 1; i <= n; i++) {
            int mid = parent[i][j - 1];
            parent[i][j] = parent[mid][j - 1];
            mindis[i][j] = min(mindis[i][j - 1], mindis[mid][j - 1]);
        }
    }
}

int minBetween(int u, int v) {
    int mini = oo;

    if(depth[u] < depth[v]) {
        swap(u,v);
    }

    int x = depth[u] - depth[v];
    for(int i = lim; i >= 0; i--) {
        if(x & (1 << i)) {
            mini = min(mini, mindis[u][i]);
            u = parent[u][i];
            x -= (1 << i);
        }
    }

    if(u == v) {
        return mini;
    }

    for(int i = lim; i >= 0; i--) {
        if(parent[u][i] != parent[v][i]) {
            mini = min({mini, mindis[u][i], mindis[v][i]});
            u = parent[u][i];
            v = parent[v][i];
        }
    }

    return min({mini, mindis[u][0], mindis[v][0]});
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

//    freopen("test.inp", "r", stdin);
//    freopen("test.out", "w", stdout);

    cin >> n >> m;

    dsu.resize(n + 1, 0);
    depth.resize(n + 1, 0);
    iota(dsu.begin(), dsu.end(), 0);

    for (int u, v, w, i = 0; i < m; i++) {
        cin >> u >> v >> w;
        edge.push_back({u, v, w});
    }

    sort(edge.begin(), edge.end());
    for (auto &[u, v, w] : edge) {
        if (join(u, v)) {
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        } else {
            nonLink.push_back({u, v, w});
        }
    }

    init();

    int res = 0;

    for(auto [u,v,w]: nonLink){
        res += minBetween(u,v) - w;
    }

    cout << res;
}
