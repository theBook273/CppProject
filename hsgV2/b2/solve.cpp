#include <bits/stdc++.h>
#define long long long long

using namespace std;

long long n, m, rx, ry, a[200][200], marked[10000], dem = 0;
long long moveSetY[] = {-1, 0, 1, 0}, moveSetX[] = {0, 1, 0, -1};

void check(long long i, long long j) {
    for (long long k = 0; k < 4; k++) {
        long long x = i + moveSetX[k], y = j + moveSetY[k];
        if (x > 0 && x <= n && y > 0 && y <= m && a[x][y] == 1) {
            marked[dem]++;
            a[x][y] = dem;
            check(x, y);
        }
    }
}

signed main() {
    cin >> n >> m >> rx >> ry;
    for (long long i = 1; i <= n; i++) {
        for (long long j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }

    for (long long i = 1; i <= n; i++) {
        for (long long j = 1; j <= m; j++) {
            if (a[i][j] == 1) {
                marked[dem]++;
                a[i][j] = dem;
                check(i, j);
                dem++;
            }
        }
    }

    for (long long i = 1; i <= n; i++) {
        for (long long j = 1; j <= m; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}
