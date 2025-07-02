#include <bits/stdc++.h>

using namespace std;
long long n, k, s, tong = 0, sizet = 0, res = 0;
vector<long long> str;

void solve(long long a) {
    if (sizet == k && tong == s) {
        res++;
        // for (auto i : str) cout << i << " ";
        // cout << endl;
        return;
    }

    for (long long i = a + 1; i <= n; i++) {
        if (tong + i <= s && sizet + 1 <= k) {
            tong += i;
            sizet++;
            str.push_back(i);
            solve(i);
            str.pop_back();
            sizet--;
            tong -= i;
        }
    }
}

long long main() {
    cin >> n >> k >> s;
    solve(0);

    cout << res;
}
