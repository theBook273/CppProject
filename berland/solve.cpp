#include <bits/stdc++.h>
#define int long long

using namespace std;

int n, m, cnt, id[100000], low[100000];
vector<int> v[100000];
vector<pair<int, int>> bridge;

void dfs(int x, int p) {
    id[x] = low[x] = ++cnt;
    for (auto u : v[x])
        if (u != p) {
            if (id[u])
                low[x] = min(low[x], id[u]);
            else {
                dfs(u, x);
                low[x] = min(low[x], low[u]);
                if (low[u] == id[u]) {
                    bridge.push_back({u, x});
                }
            }
        }
}

signed main() {
    cin.tie(NULL)->sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    for (int i = 1; i <= n; i++) {
        if (!id[i]) dfs(i, 0);
    }
}