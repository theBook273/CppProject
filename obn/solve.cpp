#include <bits/stdc++.h>
#define int long long

using namespace std;

vector<pair<int, int>> a[100001];
int disO[100001], disB[100001];

void dijikstra(int x, int dis[]) {
    dis[x] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   greater<pair<int, int>>>
        q;
    q.push({dis[x], x});

    while (!q.empty()) {
        pair<int, int> temp = q.top();
        q.pop();
        int u = temp.second;
        int kc = temp.first;
        if (kc > dis[u]) continue;
        for (auto i : a[u]) {
            int v = i.first;
            int w = i.second;
            if (dis[v] > dis[u] + w) {
                dis[v] = dis[u] + w;
                q.push({dis[v], v});
            }
        }
    }
}

main() {
    int n, m, s, t;
    cin >> n >> m >> s >> t;

    for (int i = 0; i < m; i++) {
        int x, y, z;
        cin >> x >> y >> z;

        a[x].push_back({y, z});
        a[y].push_back({x, z});
    }

    for (int i = 1; i <= n; i++) {
        disB[i] = disO[i] = 1e9;
    }

    dijikstra(s, disO);
    dijikstra(t, disB);

    // for (int i = 1; i <= n; i++) {
    //     cout << disO[i] << " ";
    // }

    int tong = 1e9, resTime = 1e9;

    for (int i = 1; i <= n; i++) {
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