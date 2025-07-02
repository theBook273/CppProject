#include <bits/stdc++.h>

using namespace std;

long long main() {
    long long s1, s2, k, tong = 0;

    cin >> s1 >> s2 >> k;

    for (long long i = s1; i <= s2; i++) {
        long long temp = i;
        while (temp != 0) {
            if (temp % 10 == k) {
                tong++;
            }
            temp /= 10;
        }
    }

    cout << tong;
}
