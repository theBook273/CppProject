#include <bits/stdc++.h>

using namespace std;
using ll = long long;

vector<ll> v[10000];
bool visited[10000];
ll tong = 0;

void bfs(ll u) {
    queue<ll> q;
    q.push(u);
    visited[u] = 1;
    // cout << u << " ";

    while (!q.empty()) {
        ll temp = q.front();
        q.pop();
        for (int i : v[temp]) {
            if (!visited[i]) {
                visited[i] = 1;
                // cout << i << " ";
                q.push(i);
            }
        }
    }
    // cout << endl;
}

signed main() {
    ll n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        ll a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            bfs(i);
            tong++;
        }
    }
    cout << tong;
}