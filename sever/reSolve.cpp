#include <bits/stdc++.h>
using namespace std;
long long const maxn = long long(1e3) + 1;
long long a[maxn][maxn];
double res[11];
long long main() {
    for (long long i = 0; i < 5; i++) {
        for (long long j = 0; j < 11; j++) {
            cin >> a[i][j];
        }
    }
    for (long long b = 0; b <= 11; b++) {
        for (long long c = 0; c <= 11; c++) {
            for (long long d = 0; d <= 11; d++) {
                for (long long e = 0; e <= 11; e++) {
                    for (long long f = 0; f <= 11; f++) {
                        double prob = (a[0][b] / 100.0) * (a[1][c] / 100.0) *
                                      (a[2][d] / 100.0) * (a[3][e] / 100.0) *
                                      (a[4][f] / 100.0);
                        long long tong = f + b + c + d + e;
                        long long diem = round(tong / 5);
                        res[diem] += prob * 100.0;
                    }
                }
            }
        }
    }
    for (double x : res) {
        for (auto i : x) cout << fixed << setprecision(10) << i << " ";
    }
}
