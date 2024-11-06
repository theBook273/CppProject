#include <bits/stdc++.h>
using namespace std;
int const maxn = int(1e3) + 1;
int a[maxn][maxn];
double res[11];
int main() {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 11; j++) {
            cin >> a[i][j];
        }
    }
    for (int b = 0; b <= 11; b++) {
        for (int c = 0; c <= 11; c++) {
            for (int d = 0; d <= 11; d++) {
                for (int e = 0; e <= 11; e++) {
                    for (int f = 0; f <= 11; f++) {
                        double prob = (a[0][b] / 100.0) * (a[1][c] / 100.0) *
                                      (a[2][d] / 100.0) * (a[3][e] / 100.0) *
                                      (a[4][f] / 100.0);
                        int tong = f + b + c + d + e;
                        int diem = round(tong / 5);
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
