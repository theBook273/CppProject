#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll n, m;
pair<ll, ll> res[100001];
vector<pair<ll, ll>> v[10000];
bool visit[10000];

void input() {
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        ll a, b, d;
        cin >> a >> b >> d;
        v[a].push_back({b, d});
        v[b].push_back({a, d});
    }
}

void solve() {
    // for (int i = 1; i <= n; i++) {
    //     cout << i << ": ";
    //     for (auto j : v[i]) {
    //         cout << j.first << " " << j.second << "|";
    //     }
    //     cout << endl;
    // }
    int x = 1;
    visit[x] = 1;

    queue<ll> q;
    q.push(x);

    while (!q.empty()) {
        x = q.front();
        q.pop();

        for (auto i : v[x]) {
            if (!visit[i.first]) {
                visit[i.first] = 1;
                q.push(i.first);
                res[i.first].first = res[x].first + i.second;
                res[i.first].second = res[x].second + 1;
            }
        }
    }

    cout << res[n].first << " " << res[n].second << endl;
}

signed main() {
    freopen("GIAOTHONG.inp", "r", stdin);
    freopen("GIAOTHONG.out", "r", stdout);
    input();
    solve();
}