#include <bits/stdc++.h>
using namespace std;
using ll = long long;
string s;

bool so(ll n) {
    double temp = n;
    while (n / 10 > 0) {
        n = 0;
        while (temp >= 1) {
            temp +=
        }
    }
}

signed main() {
    cin >> s;

    s = to_string(stoi(s) + 1);
    while (!so(s)) {
        s = to_string(stoi(s) + 1);
    }
    cout << s << endl;
}