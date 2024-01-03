
#include <bits/stdc++.h>

using namespace std;

const int n = 8;
int a[n][n];
bool hang[1000], xuoi[10000], nguoc[10000], cot[10000];

void check(int dem) {
    for (int i = dem; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!cot[i] && !nguoc[i + j - 1] && !xuoi[i - j + n]) {
                cot[i] = 1, xuoi[i] = 1, nguoc[i] = 1;
            }
        }
    }
}

int main() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
}