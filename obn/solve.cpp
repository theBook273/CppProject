#include <bits/stdc++.h>
#define long long long long

using namespace std;

vector<pair<long long, long long>> a[100001];
long long disO[100001], disB[100001];

void dijikstra(long long x, long long dis[]) {
    dis[x] = 0;
    priority_queue<pair<long long, long long>, vector<pair<long long, long long>>,
                   greater<pair<long long, long long>>>
        q;
    q.push({dis[x], x});

    while (!q.empty()) {
        pair<long long, long long> temp = q.top();
        q.pop();
        long long u = temp.second;
        long long kc = temp.first;
        if (kc > dis[u]) continue;
        for (auto i : a[u]) {
            long long v = i.first;
            long long w = i.second;
            if (dis[v] > dis[u] + w) {
                dis[v] = dis[u] + w;
                q.push({dis[v], v});
            }
        }
    }
}

main() {
    long long n, m, s, t;
    cin >> n >> m >> s >> t;

    for (long long i = 0; i < m; i++) {
        long long x, y, z;
        cin >> x >> y >> z;

        a[x].push_back({y, z});
        a[y].push_back({x, z});
    }

    for (long long i = 1; i <= n; i++) {
        disB[i] = disO[i] = 1e9;
    }

    dijikstra(s, disO);
    dijikstra(t, disB);

    // for (long long i = 1; i <= n; i++) {
    //     cout << disO[i] << " ";
    // }

    long long tong = 1e9, resTime = 1e9;

    for (long long i = 1; i <= n; i++) {
        if (disO[i] == disB[i] && disO[i] > 0 && resTime > disO[i]) {
            tong = i;
            resTime = disO[i];
        }
    }

    if (tong != 1e9)
        cout << tong;
    else
        cout << "CRY";
}
