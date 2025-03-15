#include <bits/stdc++.h>

using namespace std;
using ll = long long;

vector<ll> v[10000];
ll n, m, q;
bool visit[100000];
ll road = 0;

bool dfs(ll x, ll tar, ll re) {
    // cout << x << " ";
    if (x == tar && road == re) {
        cout << endl;
        return 1;
    }
    for (auto i : v[x]) {
        if (!visit[i]) {
            road++;
            visit[i] = 1;
            dfs(i, tar, re);
            visit[i] = 0;
            road--;
        }
    }
}

signed main() {
    cin >> n >> m >> q;
    for (int i = 0; i < m; i++) {
        ll a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    cout << dfs(1, 3, 4);
}