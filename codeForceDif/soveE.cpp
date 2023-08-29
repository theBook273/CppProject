#include <bits/stdc++.h>

using namespace std;

int n, m, a[1000][1000], res = 0;
bool check[1000][1000];
pair<int, int> moveSet[] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

void bfs(int x, int y) {
    queue<pair<int, int>> q;

    int tong = 0;

    q.push({x, y});

    tong += a[q.back().first][q.back().second];
    check[q.back().first][q.back().second] = 1;

    while (!q.empty()) {
        pair<int, int> temp;

        temp = q.front();

        q.pop();

        for (auto i : moveSet) {
            int moX = i.first + temp.first;
            int moY = i.second + temp.second;

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

int main() {
    int q;

    cin >> q;

    while (q--) {
        res = 0;

        cin >> n >> m;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> a[i][j];
                check[i][j] = 0;
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (check[i][j] == 0 && a[i][j] != 0) bfs(i, j);
            }
        }

        cout << res << endl;
    }
}