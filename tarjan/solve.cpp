#include <bits/stdc++.h>
#define long long long long

using namespace std;

vector<long long> a[100000];
long long n, m, id[100000], low[100000], cnt = 1, bridge = 0, polong long = 0;

void dfs(long long u, long long p) {
    id[u] = low[u] = ++cnt;
    long long node = (p != 0);

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
    if (node >= 2) polong long++;
}
signed main() {
    cin >> n >> m;

    for (long long i = 1; i <= m; i++) {
        long long v1, v2;
        cin >> v1 >> v2;
        a[v1].push_back(v2);
        a[v2].push_back(v1);
    }

    for (long long i = 1; i <= n; i++) {
        if (!id[i]) dfs(i, 0);
    }
    cout << polong long << " " << bridge;
}
