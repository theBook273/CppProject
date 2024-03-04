#include <bits/stdc++.h>

using namespace std;
using ll = long long;
long long s;

long long changed(int n) {
    long long res = 0;
    while (n / 10 > 0) {
        double temp = (pow(n % 10, 2));
        res += temp;
        n /= 10;
    }
    if (n != 0) {
        double temp = (pow(n, 2));
        res += temp;
    }
    return res;
}

bool so(ll n) {
    // double temp = n;
    // while (n / 10 > 0) {
    //     n = 0;
    //     while (temp >= 1) {
    //         temp +=
    //     }
    // }
}

signed main() {
    cin >> s;
    cout << changed(s);
}
