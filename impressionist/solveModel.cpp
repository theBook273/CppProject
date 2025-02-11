#include <bits/stdc++.h>

#define MAXN 400001
int l[MAXN], r[MAXN], sum[MAXN], cnt[MAXN];
void solve() {
    int n;
    std::cin >> n;
    for (int i = 1; i <= 2 * n; ++i) sum[i] = cnt[i] = 0;
    for (int i = 1; i <= n; ++i) {
        std::cin >> l[i] >> r[i];
        if (l[i] == r[i]) sum[l[i]] = 1, ++cnt[l[i]];
    }
    for (int i = 2; i <= 2 * n; ++i) sum[i] += sum[i - 1];
    for (int i = 1; i <= n; ++i)
        std::cout << ((l[i] == r[i]
                           ? cnt[l[i]] <= 1
                           : sum[r[i]] - sum[l[i] - 1] < r[i] - l[i] + 1)
                          ? "1"
                          : "0");
    std::cout << '\n';
}
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) solve();
    return 0;
}