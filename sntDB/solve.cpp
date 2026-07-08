#include <bits/stdc++.h>
#define long long long long

using namespace std;

const long long base[] = {2, 325, 9375, 28178, 450775, 9780504};
const long long add[] = {1, 3, 7, 9};

long long mul(long long a, long long b, long long mod) { return (__long long128_t(a * b) % mod); }

long long binPow(long long a, long long b, long long mod) {
    long long res = 1;
    a %= mod;
    while (b) {
        if ((b % 2)) {
            res = mul(res, a, mod);
        }
        b /= 2;
        a = mul(a, a, mod);
    }
    return res;
}

bool miller(long long n) {
    if (n < 2) return 0;
    if (n == 2 || n == 3) return 1;
    if (n % 2 == 0 || n % 3 == 0) return 0;

    long long s(0), d(n - 1);
    while (d % 2 == 0) {
        d /= 2;
        s++;
    }

    for (auto a : base) {
        if (a >= n) continue;

        long long x = binPow(a, d, n) % n;

        if (x == 1 || x == (n - 1)) continue;

        bool check = 0;

        for (long long i = 1; i <= s - 1; ++i) {
            x = mul(x, x, n);
            if (x == (n - 1)) {
                check = 1;
                break;
            }
        }

        if (!check) return check;
    }

    return 1;
}

bool xuLy(long long x) {
    bool flag = miller(x);

    if (!flag) return 0;

    flag = 0;

    for (auto so : add) {
        flag = (flag || miller(x * 10 + so));
    }

    if (!flag) return 0;

    while (x / 10) {
        flag = (flag && miller(x / 10));
        x /= 10;
    }

    return flag;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    long long n;
    long long tong(0);
    cin >> n;
    for (long long i = 0; i < n; i++) {
        long long a;
        cin >> a;
        if (xuLy(a)) {
            tong += a;
            cout << a << " ";
        }
    }

    cout << "\n" << tong;
}
