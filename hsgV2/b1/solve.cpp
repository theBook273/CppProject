#include <bits/stdc++.h>
#define int long long

using namespace std;

int toD(int n) {
    int tong = 0;
    string s = to_string(n);

    for (int i = s.size() - 1; i >= 0; i--) {
        if (s[i] != '0') {
            tong += (pow(2, s.size() - (i + 1)));
        }
    }
    return tong;
}

signed main() {
    int n;

    cin >> n;

    cout << toD(n) + n;
}