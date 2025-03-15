#include <bits/stdc++.h>

using namespace std;
using ll = unsigned long long;

ll lcm(ll a, ll b) { return a * b / __gcd(a, b); }

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll a, b, c;
    cin >> a >> b >> c;

    ll res(lcm(a, lcm(b, c)));

    ll x(1);

    while ((x * x) % res != 0) {
        ++x;
    }
    cout << x;
}
