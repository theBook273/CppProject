#include <bits/stdc++.h>
#define int long long

using namespace std;

vector<int> a[100000];
int n, m, id[100000], low[100000], cnt = 1, bridge = 0, point = 0;

void dfs(int u, int p) {
    id[u] = low[u] = ++cnt;
    int node = (p != 0);

    for (auto v : a[u])
        if (v != p) {
            if (id[v])
                low[u] = min(id[v], low[u]);
            else {
                dfs(v, u);
                low[u] = min(low[v], low[u]);
                if (id[v] == low[v]) {
                    bridge++;
                    cout << u << " " << v << endl;
                }
                if (low[v] >= id[u]) node++;
            }
        }
    if (node >= 2) point++;
}
signed main() {
    cin >> n >> m;

    for (int i = 1; i <= m; i++) {
        int v1, v2;
        cin >> v1 >> v2;
        a[v1].push_back(v2);
        a[v2].push_back(v1);
    }

    for (int i = 1; i <= n; i++) {
        if (!id[i]) dfs(i, 0);
    }
    cout << point << " " << bridge;
}