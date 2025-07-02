#include <bits/stdc++.h>
using namespace std;

long long text_lenght;
long long L, R, prefix_hash31[2000001], prefix_base31[2000001],
    prefix_hash37[2000001], prefix_base37[2000001];
const long long MOD = 1e9 + 7;
const long long MOD2 = 1e9 + 9;
const long long base = 31;
const long long base2 = 43;

string text;

void input() {
    cin >> text_lenght;
    cin >> text;
    text = '|' + text;
}

// bool store[40000004], store2[40000004];
pair<long long, long long> p[2000001];
bool check(long long mid) {
    // memset(p,0,sizeof(p));
    // memset(store2,0,sizeof(store2));

    long long k = mid;

    for (long long i = 1; i + k - 1 <= text_lenght; i++) {
        long long l = i, r = i + k - 1;

        long long cur_hash31 =
            (prefix_hash31[r] - prefix_hash31[l - 1] * prefix_base31[k] +
             1ll * MOD * MOD) %
            MOD;
        long long cur_hash37 =
            (prefix_hash37[r] - prefix_hash37[l - 1] * prefix_base37[k] +
             1ll * MOD2 * MOD2) %
            MOD2;
        p[i] = {cur_hash31, cur_hash37};
        // cout << cur_hash31 << ' ' << cur_hash37 <<"\n";
    }
    sort(p, p + (text_lenght - k + 1));
    for (long long i = 1; i + k - 1 <= text_lenght; i++) {
        if (p[i].first == p[i - 1].first && p[i].second == p[i - 1].second)
            return true;
    }

    return false;
}

void solve() {
    L = 1;
    R = text_lenght;

    prefix_base31[0] = 1;
    prefix_base37[0] = 1;
    for (long long i = 1; i <= text_lenght; i++) {
        prefix_hash31[i] =
            (prefix_hash31[i - 1] * base + text[i] - 'a' + 1) % MOD;
        prefix_base31[i] = (prefix_base31[i - 1] * base) % MOD;

        prefix_hash37[i] =
            (prefix_hash37[i - 1] * base2 + text[i] - 'a' + 1) % MOD2;
        prefix_base37[i] = (prefix_base37[i - 1] * base2) % MOD2;
    }

    while (L <= R) {
        long long mid = (L + R) / 2;

        if (check(mid))
            L = mid + 1;
        else
            R = mid - 1;
    }
    cout << R;
}

long long main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input(), solve();
}
