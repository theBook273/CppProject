#include <bits/stdc++.h>
#define REP(i, a, b) for (int i = a; i <= b; i++)

using namespace std;

vector<long> road[500001];
bool visited[500001];
int h[500001];
long m, n, k, group = 1;

void bfs(long u) {
    visited[u] = 1;
    queue<int> q;
    q.push(u);

    while (!q.empty()) {
        int temp = q.front();
        q.pop();

        for (int i : road[temp]) {
            if (!visited[i] && h[i] <= h[temp]) {
                visited[i] = 1;
                group++;
                q.push(i);
            }
        }
    }
}

int main() {
    cin.tie(NULL)->sync_with_stdio(false);
    cin >> m >> n >> k;
    REP(i, 1, m) { cin >> h[i]; }
    REP(i, 1, n) {
        long u, v;
        cin >> u >> v;
        road[u].push_back(v);
        road[v].push_back(u);
    }
    bfs(k);
    cout << group;
}
