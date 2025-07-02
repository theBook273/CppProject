#include <bits/stdc++.h>
#define long long long long

using namespace std;

long long n, m, cnt, id[100000], low[100000];
vector<long long> v[100000];
vector<pair<long long, long long>> bridge;

void dfs(long long x, long long p) {
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
    for (long long i = 1; i <= m; i++) {
        long long a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    for (long long i = 1; i <= n; i++) {
        if (!id[i]) dfs(i, 0);
    }
}
