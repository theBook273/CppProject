#include <bits/stdc++.h>
#define int long long

using namespace std;

double v[10000], temp;
int w[10000];

signed main() {
    int n, p, l;
    cin >> n >> p >> l;
    for (int i = 0; i < n; i++) {
        cin >> w[i] >> v[i];
        temp += l / v[i];
    }

    double speed = v[0], res = 0;
    int tong = w[0];
    for (int i = 1; i <= n; i++) {
        if (tong + w[i] <= p && speed >= v[i]) {
            tong += w[i];
        } else {
            // cout << speed << endl;
            res += (l / speed);
            tong = w[i];
            speed = v[i];
        }
    }
    if (tong <= p) res += (l / speed);
    cout << fixed << setprecision(2) << res << endl;
}