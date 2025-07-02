#include <bits/stdc++.h>
using namespace std;

long long main() {
    long long n;
    cin >> n;
    while (n) {
        n -= ceil(n / 2.0);
        cout << n << endl;
    }
}
