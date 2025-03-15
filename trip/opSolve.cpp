#include <bits/stdc++.h>
#define int int
using namespace std;

int n, a[17][17], dis[1 << 17][17];

main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    for (int mask = 1; mask < (int)pow(2, n); mask++) {
        if (__builtin_popcount(mask) == 1)
            continue;
        else
            for (int i = 0; i < n; i++) {
                if ((mask >> i) & 1 == 1) {
                    dis[mask][i] = 1e9;
                    int temp = mask ^ (1 << i);
                    for (int j = 0; j < n; j++) {
                        if (((temp >> j) & 1) == 1) {
                            dis[mask][i] =
                                min(dis[mask][i], dis[temp][j] + a[j][i]);
                        }
                    }
                }
            }
    }
    int ans = 1e9;
    for (int i = 0; i < n; i++) {
        ans = min(ans, dis[(1 << n) - 1][i]);
    }
    cout << ans;
}
