#include <bits/stdc++.h>
#define long long long long

using namespace std;

const long long maxn = 1e3 + 8;

long long a[maxn][maxn], b[maxn][maxn];

signed main() {
    cin.tie(NULL)->sync_with_stdio(false);

    long long t;
    cin >> t;
    while (t--) {
        long long n, m;
        cin >> n >> m;
        string s;
        cin >> s;
        for (long long i = 0; i < n; i++) {
            for (long long j = 0; j < m; j++) {
                cin >> a[i][j];
            }
        }

        long long x = 0, y = 0;
        long long tong = 0;

        for (auto c : s) {
            tong = 0;
            if (c == 'D') {
                for (long long j = 0; j < m; j++) {
                    tong += a[x][j];
                }
                a[x][y] -= tong;
                x++;
            } else {
                for (long long i = 0; i < n; i++) {
                    tong += a[i][y];
                }
                a[x][y] -= tong;
                y++;
            }
        }

        tong = 0;
        for (long long j = 0; j < m; j++) {
            tong += a[x][j];
        }
        a[x][y] -= tong;

        for (long long i = 0; i < n; i++) {
            for (long long j = 0; j < m; j++) {
                cout << a[i][j] << " ";
            }
            cout << endl;
        }
    }
}
