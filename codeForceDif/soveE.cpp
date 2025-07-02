#include <bits/stdc++.h>

using namespace std;

long long n, m, a[1000][1000], res = 0;
bool check[1000][1000];
pair<long long, long long> moveSet[] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

void bfs(long long x, long long y) {
    queue<pair<long long, long long>> q;

    long long tong = 0;

    q.push({x, y});

    tong += a[q.back().first][q.back().second];
    check[q.back().first][q.back().second] = 1;

    while (!q.empty()) {
        pair<long long, long long> temp;

        temp = q.front();

        q.pop();

        for (auto i : moveSet) {
            long long moX = i.first + temp.first;
            long long moY = i.second + temp.second;

            if (moX >= 0 && moY >= 0 && moX < n && moY < m &&
                a[moX][moY] != 0 && check[moX][moY] == 0) {
                tong += a[moX][moY];
                check[moX][moY] = 1;
                q.push({moX, moY});
            }
        }
    }

    res = max(res, tong);
}

long long main() {
    long long q;

    cin >> q;

    while (q--) {
        res = 0;

        cin >> n >> m;

        for (long long i = 0; i < n; i++) {
            for (long long j = 0; j < m; j++) {
                cin >> a[i][j];
                check[i][j] = 0;
            }
        }

        for (long long i = 0; i < n; i++) {
            for (long long j = 0; j < m; j++) {
                if (check[i][j] == 0 && a[i][j] != 0) bfs(i, j);
            }
        }

        cout << res << endl;
    }
}
