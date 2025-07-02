#include <bits/stdc++.h>
#define long long long long

using namespace std;

long long toD(long long n) {
    long long tong = 0;
    string s = to_string(n);

    for (long long i = s.size() - 1; i >= 0; i--) {
        if (s[i] != '0') {
            tong += (pow(2, s.size() - (i + 1)));
        }
    }
    return tong;
}

signed main() {
    long long n;

    cin >> n;

    cout << toD(n) + n;
}
