#include <bits/stdc++.h>

using namespace std;

int a[3] = {0, 0, 0};
int x;

bool check() {
    if (a[0] < x) return 0;
    if (a[1] < x) return 0;
    if (a[2] < x) return 0;
    return 1;
}

int minx(int b) {
    int res = 1e9;
    for (int i = 0; i < 3; i++) {
        if (i == b) continue;
        res = min(res, a[i]);
    }
    return res;
}

signed main() {
    int t;
    cin >> t;
    while (t--) {
        a[0] = a[1] = a[2] = 0;
        cin >> x;
        int dem = 0;
        while (!check()) {
            for (int i = 0; i < 3; i++) {
                a[i] = 2 * minx(i) + 1;
                if (a[i] > x) a[i] = x;
                // for (int i = 0; i < 3; ++i) cout << a[i] << " ";
                // cout << "\n";
                dem++;
                if (check()) break;
            }
        }
        cout << dem << "\n";
    }
}