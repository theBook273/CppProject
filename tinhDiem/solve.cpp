#include <bits/stdc++.h>

using namespace std;
using ll = long long;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll a, b, c, x;

    cin >> a >> b >> c >> x;

    ll ax, bx, cx;
    ax = (ll)abs(a - x);
    bx = (ll)abs(b - x);
    cx = (ll)abs(c - x);

    if (ax < bx && ax < cx) {
        cout << (ll)a;
    } else if (bx < ax && bx < cx) {
        cout << (ll)b;
    } else if (cx < ax && cx < bx)
        cout << (ll)c;
}