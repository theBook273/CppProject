#include <bits/stdc++.h>

#define MAXN 400001
long long l[MAXN], r[MAXN], sum[MAXN], cnt[MAXN];
void solve() {
    long long n;
    std::cin >> n;
    for (long long i = 1; i <= 2 * n; ++i) sum[i] = cnt[i] = 0;
    for (long long i = 1; i <= n; ++i) {
        std::cin >> l[i] >> r[i];
        if (l[i] == r[i]) sum[l[i]] = 1, ++cnt[l[i]];
    }
    for (long long i = 2; i <= 2 * n; ++i) sum[i] += sum[i - 1];
    for (long long i = 1; i <= n; ++i)
        std::cout << ((l[i] == r[i]
                           ? cnt[l[i]] <= 1
                           : sum[r[i]] - sum[l[i] - 1] < r[i] - l[i] + 1)
                          ? "1"
                          : "0");
    std::cout << '\n';
}
long long main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);
    long long t;
    std::cin >> t;
    while (t--) solve();
    return 0;
}
