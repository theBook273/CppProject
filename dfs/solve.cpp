#include <bits/stdc++.h>

using namespace std;

vector<long long> v[1000000];

bool checked[1000000], able = 0;
long long n, m, s, t, trace[1000000];
stack<long long> res;

void bfs(long long x) {
    checked[x] = 1;
    trace[x] = x;

    queue<long long> q;
    q.push(x);

    while (!q.empty()) {
        long long temp = q.front();

        q.pop();
        for (long long i : v[temp]) {
            if (!checked[i]) {
                if (i == t) {
                    trace[i] = temp;
                    able = 1;
                    return;
                }
                q.push(i);
                checked[i] = 1;
                trace[i] = temp;
            }
        }
    }
}

void reveal(long long x) {
    if (trace[x] != x) {
        res.push(x);
        reveal(trace[x]);
    } else
        res.push(x);
}

long long main() {
    cin >> n >> m >> s >> t;

    for (long long i = 0; i < m; i++) {
        long long a, b;

        cin >> a >> b;

        checked[a] = 0;
        checked[b] = 0;

        v[a].push_back(b);
        v[b].push_back(a);
    }

    for (long long i = 1; i <= n; i++) {
        sort(v[i].begin(), v[i].end());
    }

    bfs(s);

    if (!able) {
        cout << -1;
    } else {
        reveal(t);

        while (!res.empty()) {
            cout << res.top() << " ";
            res.pop();
        }
    }
}
