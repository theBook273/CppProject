#include <bits/stdc++.h>
#define long long long long

using namespace std;

long long n, m, posx, posy;
long long temp = 2, target = 0, res = 1e9;
long long a[105][105], board[105][105];
long long directX[4] = {1, 0, -1, 0};
long long directY[4] = {0, 1, 0, -1};

map<long long, long long> mp;

void color(long long x, long long y) {
    long long sizeOfA = 1;
    queue<pair<long long, long long>> q;
    q.push({x, y});
    a[x][y] = temp;

    while (!q.empty()) {
        x = q.front().first;
        y = q.front().second;
        q.pop();
        for (long long i = 0; i < 4; i++) {
            if (a[x + directX[i]][y + directY[i]] == 1) {
                q.push({x + directX[i], y + directY[i]});
                a[x + directX[i]][y + directY[i]] = temp;
                sizeOfA++;
            }
        }
    }

    mp[temp] = sizeOfA;
    target = max(target, sizeOfA);

    temp++;
}

void solve(long long x, long long y) {
    queue<pair<long long, long long>> q;
    q.push({x, y});
    a[x][y] = -1;

    while (!q.empty()) {
        x = q.front().first;
        y = q.front().second;
        q.pop();
        for (long long i = 0; i < 4; i++) {
            if (a[x + directX[i]][y + directY[i]] != -1) {
                board[x + directX[i]][y + directY[i]] = board[x][y] + 1;
                if (board[x + directX[i]][y + directY[i]] != 0) {
                    if (mp[a[x + directX[i]][y + directY[i]]] == target) {
                        res = min(res, board[x + directX[i]][y + directY[i]]);
                    }
                }
                a[x + directX[i]][y + directY[i]] = -1;
                q.push({x + directX[i], y + directY[i]});
            }
        }
    }
}

signed main() {
    cin.tie(NULL)->sync_with_stdio(false);

    cin >> n >> m >> posx >> posy;

    for (long long i = 0; i <= n + 1; i++) {
        for (long long j = 0; j <= m + 1; j++) {
            a[i][j] = -1;
        }
    }

    for (long long i = 1; i <= n; i++) {
        for (long long j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }

    for (long long i = 1; i <= n; i++) {
        for (long long j = 1; j <= m; j++) {
            if (a[i][j] == 1) {
                color(i, j);
            }
        }
    }

    // for (long long i = 0; i <= n + 1; i++) {
    //     for (long long j = 0; j <= m + 1; j++) {
    //         cout << a[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    solve(posx, posy);

    cout << res;
}
