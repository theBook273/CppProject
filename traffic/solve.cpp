#include <bits/stdc++.h>

using namespace std;
using ll = long long;

vector<pair<long long, long long>> v[10000];
ll dis[10000];
ll n, m;
map<long long, long long> mp;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // freopen("GIAOTHONG.inp", "r", stdin);
    // freopen("GIAOTHONG.out", "w", stdout);

    cin >> n >> m;

    for (long long i = 0; i < m; i++) {
        ll a, b, l;
        cin >> a >> b >> l;

        dis[a] = 1e9;
        dis[b] = 1e9;

        v[a].push_back({b, l});
        v[b].push_back({a, l});
    }

    long long x = 1;
    dis[1] = 0;
    stack<long long> q;
    q.push(x);

    while (!q.empty()) {
        x = q.top();
        q.pop();

        if (x == n) {
            mp[dis[x]]++;
            dis[x] = 1e9;
        }

        for (auto i : v[x]) {
            if (dis[i.first] >= dis[x] + i.second) {
                dis[i.first] = dis[x] + i.second;
                q.push(i.first);
            }
        }
    }

    for (auto i : mp) {
        cout << i.first << " " << i.second << endl;
        break;
    }
}
