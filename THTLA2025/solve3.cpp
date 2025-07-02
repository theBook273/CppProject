#include <bits/stdc++.h>

using namespace std;

long long tong = 0;

void solve(long long x) {
    tong += x;
    if (x == 1) return;
    long long l = floor(x / 2.0);
    long long r = ceil(x / 2.0);
    solve(l);
    solve(r);
}

signed main() {
    long long n, m;
    cin >> n >> m;
    solve(n * m);
    cout << tong;
}
