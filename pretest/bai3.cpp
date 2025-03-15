#include <bits/stdc++.h>
#define int long long

using namespace std;

const int maxn = 1e3 + 8;

int a[maxn][maxn], b[maxn][maxn];

signed main() {
    cin.tie(NULL)->sync_with_stdio(false);

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        string s;
        cin >> s;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> a[i][j];
            }
        }

        int x = 0, y = 0;
        int tong = 0;

        for (auto c : s) {
            tong = 0;
            if (c == 'D') {
                for (int j = 0; j < m; j++) {
                    tong += a[x][j];
                }
                a[x][y] -= tong;
                x++;
            } else {
                for (int i = 0; i < n; i++) {
                    tong += a[i][y];
                }
                a[x][y] -= tong;
                y++;
            }
        }

        tong = 0;
        for (int j = 0; j < m; j++) {
            tong += a[x][j];
        }
        a[x][y] -= tong;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cout << a[i][j] << " ";
            }
            cout << endl;
        }
    }
}