#include <bits/stdc++.h>
#define long long unsigned long long

using namespace std;

signed main() {
    long long n, p;
    cin >> n >> p;
    long long d = 1;
    p += !(p % 2);
    d = ((p + 1) / 2) - 1;
    long long temp = n / 2 - d;
    cout << min(d, temp) << endl;
}
