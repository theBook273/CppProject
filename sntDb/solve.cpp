#include <bits/stdc++.h>
#define int long long

using namespace std;

const int base[] = {2, 325, 9375, 28178, 450775, 9780504};
const int add[] = {1, 3, 7, 9};

int mul(int a, int b, int mod) { return (__int128_t(a * b) % mod); }

int binPow(int a, int b, int mod) {
    int res = 1;
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

bool miller(int n) {
    if (n < 2) return 0;
    if (n == 2 || n == 3) return 1;
    if (n % 2 == 0 || n % 3 == 0) return 0;

    int s(0), d(n - 1);
    while (d % 2 == 0) {
        d /= 2;
        s++;
    }

    for (auto a : base) {
        if (a >= n) continue;

        int x = binPow(a, d, n) % n;

        if (x == 1 || x == (n - 1)) continue;

        bool check = 0;

        for (int i = 1; i <= s - 1; ++i) {
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

bool xuLy(int x) {
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
    int n;
    int tong(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        if (xuLy(a)) {
            tong += a;
            cout << a << " ";
        }
    }

    cout << "\n" << tong;
}
