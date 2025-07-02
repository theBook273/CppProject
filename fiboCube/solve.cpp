#include <bits/stdc++.h>

using namespace std;

const double gol1 = (1 + sqrt(5)) / 2.0;
const double gol2 = (1 - sqrt(5)) / 2.0;

double binet(int x) { return (1 / sqrt(5)) * (pow(gol1, x) - pow(gol2, x)); }

signed main() {
    int t;
    cin >> t;
    while (t--) {
        int c[3];
        int n, m;

        cin >> n >> m;

        c[0] = c[1] = binet(n + 1);
        c[2] = binet(n) + binet(n + 1);

        sort(c, c + 3);

        for (int i = 0; i < m; i++) {
            int a[3];
            cin >> a[0] >> a[1] >> a[2];
            sort(a, a + 3);
            if (a[0] >= c[0] && a[1] >= c[1] && a[2] >= c[2])
                cout << 1;
            else
                cout << 0;
        }
        cout << "\n";
    }
}