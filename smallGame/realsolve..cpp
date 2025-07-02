#include <bits/stdc++.h>

#include <vector>
using namespace std;
// SPEED UP
#pragma GCC optimize("O2")
#pragma GCC optimize("-ftree-vectorize")
// #pragma GCC optimize("O3") //how good is this? lol
// #pragma GCC target("avx,avx2,sse,sse2,sse3,sse4,popcnt,fma")
// #pragma GCC optimize("unroll-loops")
#define fast_io                   \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
//============================================================================
// START PROGRAM
//============================================================================
#define long long long long
#define endl '\n'

long long solve(long long n, long long k) {
    // cerr<<n<<' '<<k<<endl;
    if (n == 1) return 1;
    if (k <= (n + 1) / 2) {
        if (2 * k > n)
            return 2 * k % n;
        else
            return 2 * k;
    }

    long long c = solve(n / 2, k - (n + 1) / 2);
    if (n & 1)
        return 2 * c + 1;
    else
        return 2 * c - 1;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    long long t;
    cin >> t;
    while (t--) {
        long long n, k;
        cin >> n >> k;
        cout << solve(n, k) << endl;
    }
}
