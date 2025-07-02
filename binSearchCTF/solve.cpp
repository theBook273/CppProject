#include <bits/stdc++.h>

using namespace std;

long long main() {
    long long l = 1, r = 1000;
    while (l <= r) {
        long long m = (l + r) / 2;
        cout << m << endl;
        bool check;
        cout << "bigger?: ";
        cin >> check;
        if (check) {
            l = m + 1;
        } else {
            r = m - 1;
        }
    }
}
