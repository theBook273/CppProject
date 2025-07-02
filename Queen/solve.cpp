
#include <bits/stdc++.h>

using namespace std;

const long long n = 8;
long long a[n][n];
bool hang[1000], xuoi[10000], nguoc[10000], cot[10000];

void check(long long dem) {
    for (long long i = dem; i < n; i++) {
        for (long long j = 0; j < n; j++) {
            if (!cot[i] && !nguoc[i + j - 1] && !xuoi[i - j + n]) {
                cot[i] = 1, xuoi[i] = 1, nguoc[i] = 1;
            }
        }
    }
}

long long main() {
    for (long long i = 0; i < n; i++) {
        for (long long j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
}
