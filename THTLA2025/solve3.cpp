#include <bits/stdc++.h>

using namespace std;

int tong = 0;

void solve(int x) {
    tong += x;
    if (x == 1) return;
    int l = floor(x / 2.0);
    int r = ceil(x / 2.0);
    solve(l);
    solve(r);
}

signed main() {
    int n, m;
    cin >> n >> m;
    solve(n * m);
    cout << tong;
}