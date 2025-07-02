#include <bits/stdc++.h>

using namespace std;

long long main() {
    long long n, m;

    cin >> n >> m;

    char a[n];

    long long b[n];

    for (long long i = 0; i < n; i++) {
        cin >> a[i];
        b[i] = a[i];
    }

    for (long long i = 0; i < n; i++) {
        if ('a' <= a[i] && a[i] <= 'z') {
            a[i] = toupper(a[i]);
        } else {
            b[i] += m;
            while (b[i] > 'Z') {
                b[i] = b[i] - ('Z' - 'A' + 1) * (b[i] / 'Z');
            }
            a[i] = b[i];
        }
    }

    for (auto i : a) {
        cout << i;
    }
}
