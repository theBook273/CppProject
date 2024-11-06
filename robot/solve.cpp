#include <bits/stdc++.h>
#define int long long

using namespace std;

int n, m, posx, posy;
int temp = 2, target = 0, res = 1e9;
int a[105][105], board[105][105];
int directX[4] = {1, 0, -1, 0};
int directY[4] = {0, 1, 0, -1};

map<int, int> mp;

void color(int x, int y) {
    int sizeOfA = 1;
    queue<pair<int, int>> q;
    q.push({x, y});
    a[x][y] = temp;

    while (!q.empty()) {
        x = q.front().first;
        y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
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

void solve(int x, int y) {
    queue<pair<int, int>> q;
    q.push({x, y});
    a[x][y] = -1;

    while (!q.empty()) {
        x = q.front().first;
        y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
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

    for (int i = 0; i <= n + 1; i++) {
        for (int j = 0; j <= m + 1; j++) {
            a[i][j] = -1;
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i][j] == 1) {
                color(i, j);
            }
        }
    }

    // for (int i = 0; i <= n + 1; i++) {
    //     for (int j = 0; j <= m + 1; j++) {
    //         cout << a[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    solve(posx, posy);

    cout << res;
}