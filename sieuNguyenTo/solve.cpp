#include <bits/stdc++.h> #define int long long

using namespace std;

const int base[] = {2, 325, 9375, 28178, 450775, 9780504, 1795265022};

const string s[] = {"NO", "YES"};

int mul(int a, int b, int mod) { return (__int128(a * b) % mod); }

int binPow(int a, int b, int mod) {
    int res = 1;
    a %= mod;
    while (b) {
        if (b % 2) res = mul(res, a, mod);
        b /= 2;
        a = mul(a, a, mod);
    }
    return res;
}

bool miller(int n) {
    if (n < 2) return 0;
    if (n == 2 || n == 3) return 1;
    if (n % 2 == 0 || n % 3 == 0) return 0;

    int s = 0, d = n - 1;
    while (!(d % 2)) {
        d /= 2;
        s++;
    }

    for (auto a : base) {
        if (a >= n) continue;
        int x = binPow(a, d, n) % n;
        if (x == 1 || x == n - 1) continue;

        bool check = 0;

        for (int i = 1; i <= s - 1; ++i) {
            x = mul(x, x, n);
            check = (check || (x == n - 1));
            if (check) break;
        }

        if (!check) return check;
    }
    return 1;
}

bool check(int x) {
    while (x) {
        if (!miller(x)) return 0;
        x /= 10;
    }
    return 1;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int n;
    cin >> n;
    cout << s[check(n)];
}