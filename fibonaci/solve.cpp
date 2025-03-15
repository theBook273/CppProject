#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MOD = 1e9 + 7;

struct matrix {
    int a[2][2];

    matrix() { memset(a, 0, sizeof(a)); }
};

matrix operator*(const matrix a, const matrix b) {
    matrix c;

    (c.a[0][0] += (a.a[0][0] * b.a[0][0] + a.a[0][1] * b.a[1][0]) % MOD) %= MOD;
    (c.a[0][1] += (a.a[0][0] * b.a[0][1] + a.a[0][1] * b.a[1][1]) % MOD) %= MOD;
    (c.a[1][0] += (a.a[1][0] * b.a[0][0] + a.a[1][1] * b.a[1][0]) % MOD) %= MOD;
    (c.a[1][1] += (a.a[1][0] * b.a[0][1] + a.a[1][1] * b.a[1][1]) % MOD) %= MOD;

    return c;
}

matrix Pow(const matrix &a, int n) {
    if (n <= 1) return a;
    if (n % 2 == 1)
        return Pow(a * a, n / 2) * a;
    else
        return Pow(a * a, n / 2);
}

int n;

signed main() {
    cin.tie(NULL)->sync_with_stdio(false);
    matrix t, u;
    cin >> n;

    if (n == 0) {
        return cout << 0, 0;
    }

    u.a[0][0] = 1;
    t.a[0][0] = t.a[0][1] = t.a[1][0] = 1;

    t = Pow(t, n - 1);

    matrix res = t * u;
    cout << res.a[0][0] << endl;
}