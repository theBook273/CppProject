#include <bits/stdc++.h>

using namespace std;
using ll = long long;

float tongUoc(int n) {
    int tong = 0;
    for (int i = 1; i <= sqrt(n); i++) {
        if (n % i == 0) {
            tong += i;
            if (i != n / i) {
                tong += n / i;
            }
        }
    }
    return tong;
}

signed main() {
    int n;

    cin >> n;

    float s1 = tongUoc(n);

    for (int i = n + 1; i < 100000; i++) {
        if (s1 * i == tongUoc(i) * n) {
            cout << i;
            break;
        }
    }
}