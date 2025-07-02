#include <bits/stdc++.h>

using namespace std;

long long main() {
    long long n;

    cin >> n;

    for (long long i = 0; i < n; i++) {
        long long a;

        cin >> a;

        long long dem = 1;

        while (a - dem >= 0) {
            a -= dem;
            dem++;
        }

        cout << ((a == 0) ? "YES \n" : "NO \n");
    }
}
