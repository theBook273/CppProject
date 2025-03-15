#include <bits/stdc++.h>
#define int unsigned long long

using namespace std;

signed main() {
    int n, p;
    cin >> n >> p;
    int d = 1;
    p += !(p % 2);
    d = ((p + 1) / 2) - 1;
    int temp = n / 2 - d;
    cout << min(d, temp) << endl;
}