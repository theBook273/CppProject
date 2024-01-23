#include <bits/stdc++.h>

using namespace std;

vector<int> v[1000000];

bool checked[1000000], able = 0;
int n, m, s, t, trace[1000000];
stack<int> res;

void bfs(int x) {
    checked[x] = 1;
    trace[x] = x;

    queue<int> q;
    q.push(x);

    while (!q.empty()) {
        int temp = q.front();

        q.pop();
        for (int i : v[temp]) {
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

void reveal(int x) {
    if (trace[x] != x) {
        res.push(x);
        reveal(trace[x]);
    } else
        res.push(x);
}

int main() {
    cin >> n >> m >> s >> t;

    for (int i = 0; i < m; i++) {
        int a, b;

        cin >> a >> b;

        checked[a] = 0;
        checked[b] = 0;

        v[a].push_back(b);
        v[b].push_back(a);
    }

    for (int i = 1; i <= n; i++) {
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