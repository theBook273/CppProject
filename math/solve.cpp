#include <bits/stdc++.h>
using namespace std;

long long a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
bool check[10000];

vector<long long> bruh;
long long res = 0;

void solve() {
    if (bruh.size() == 4) {
        long long tong = 0;
        for (auto i : bruh) {
            tong += i;
        }
        if (tong % 11 == 0 &&
            (bruh[0] - bruh[1] + bruh[2] - bruh[3]) % 11 == 0) {
            res++;
        }
        return;
    }
    for (long long i = 0; i < 9; i++) {
        if (!check[a[i]]) {
            bruh.push_back(a[i]);
            check[a[i]] = 1;
            solve();
            bruh.pop_back();
            check[a[i]] = 0;
        }
    }
}

main() {
    solve();
    cout << res;
}
