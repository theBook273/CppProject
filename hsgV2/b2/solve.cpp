#include <bits/stdc++.h>
#define int long long

using namespace std;

int n, m, rx, ry, a[200][200], marked[10000], dem = 0;
int moveSetY[] = {-1, 0, 1, 0}, moveSetX[] = {0, 1, 0, -1};

void check(int i, int j) {
    for (int k = 0; k < 4; k++) {
        int x = i + moveSetX[k], y = j + moveSetY[k];
        if (x > 0 && x <= n && y > 0 && y <= m && a[x][y] == 1) {
            marked[dem]++;
            a[x][y] = dem;
            check(x, y);
        }
    }
}

signed main() {
    cin >> n >> m >> rx >> ry;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i][j] == 1) {
                marked[dem]++;
                a[i][j] = dem;
                check(i, j);
                dem++;
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}