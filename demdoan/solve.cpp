#include <bits/stdc++.h>
#define int long long
using namespace std;

const int maxn = 1e6 + 27;
const int base[] = {2, 325, 9375, 28178, 450775, 9780504, 1795265022};

int mul(int a, int b, int mod) { return (__int128(a * b) % mod); }

int binPow(int a, int b, int mod) {
    int res = 1;
    a %= mod;
    while (b) {
        if (b % 2 == 1) res = mul(res, a, mod);
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

    for (auto orig_a : base) {
        int a = orig_a % n;
        if (a == 0) continue;
        int x = binPow(a, d, n);

        if (x == 1 || x == n - 1) continue;

        bool check = 0;
        for (int i = 1; i <= s - 1; ++i) {
            x = mul(x, x, n);
            check = (check || (x == n - 1));
            if (check) break;
        }
        if (!check) return false;
    }
    return true;
}

int prefix[maxn];

signed main() {
    cin.tie(0)->sync_with_stdio(0);

    prefix[1] = miller(1);

    for (int i = 2; i < maxn; ++i) {
        prefix[i] = prefix[i - 1] + miller(i);
    }

    int t;
    cin >> t;
    while (t--) {
        int l, r;
        cin >> l >> r;
        cout << prefix[r] - prefix[l - 1] << "\n";
    }
}