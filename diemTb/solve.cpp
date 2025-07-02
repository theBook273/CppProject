#include <bits/stdc++.h>
#define long long long long

using namespace std;

double a[5][11], tong = 0, check = 1;
double v[11];

void solve(long long x) {
    if (x == 5) {
        long long temp = ceil(tong / 5);
        v[temp] += (check / pow(100, 5));
        return;
    }
    for (long long i = 0; i < 11; i++) {
        if (a[x][i] == 0) continue;
        tong += i;
        check *= a[x][i];
        solve(x + 1);
        tong -= i;
        check /= a[x][i];
    }
}

signed main() {
    for (long long i = 0; i < 5; i++) {
        for (long long j = 0; j < 11; j++) {
            cin >> a[i][j];
        }
    }
    solve(0);

    for (long long i = 0; i < 11; i++) {
        cout << fixed << setprecision(10) << v[i] * 100 << " ";
    }
}
