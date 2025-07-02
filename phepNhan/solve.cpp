#include <bits/stdc++.h>
#define long long long long
using namespace std;

vector<long long> each;

bool bigger(string a, string b) {
    if (a.size() > b.size()) return 1;
    if (a.size() < b.size()) return 0;

    for (long long i = 0; i < a.size(); i++) {
        if (a[i] < b[i])
            return 0;
        else
            return 1;
    }

    return 1;
}

void eachMul(string a, string b) {
    for (long long i = b.size() - 1; i >= 0; i--)
        each.push_back((b[i] - '0') * stoull(a));
}
signed main() {
    string a;
    string b;
    char mark;

    cin >> a >> mark >> b;

    if (!bigger(a, b)) swap(a, b);

    eachMul(a, b);
    for (auto i : each) cout << i << "\n";

    string res =
        to_string((long long)((__long long128_t)stoull(a) * (__long long128_t)stoull(b)));

    long long cn = b - a.size()
}
