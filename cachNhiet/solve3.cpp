#include <bits/stdc++.h>

using namespace std;
using ll = long long;
long long s;
map<ll, bool> visited;
long long changed(ll n) {
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
    visited[n] = 1;
    n = changed(n);
    // cout << n << endl;
    do {
        visited[n] = 1;
        n = changed(n);
        // cout << n << endl;
    } while (!visited[n] && n != 1);
    return n == 1;
}

signed main() {
    cin >> s;
    s++;
    while (!so(s)) {
        s++;
    }
    cout << s << endl;
}
