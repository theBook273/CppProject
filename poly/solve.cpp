#include <bits/stdc++.h>
#define endl '\n'
#define long long long long

using namespace std;

double area(pair<long long, long long> a, pair<long long, long long> b, pair<long long, long long> c,
            pair<long long, long long> d) {
    double tich1(a.first * b.second + b.first * c.second + c.first * d.second +
                 d.first * a.second);
    double tich2(a.second * b.first + b.second * c.first + c.second * d.first +
                 d.second * a.first);

    return (0.5) * double(abs(tich1 - tich2));
}
main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long n;
    cin >> n;
    pair<long long, long long> a[n];
    for (long long i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
    }
    double res(0);
    for (long long i = 0; i < n - 4; ++i) {
        for (long long j = i + 1; j < n; ++j) {
            for (long long k = j + 1; k < n; ++k) {
                for (long long l = k + 1; l < n; ++l) {
                    res = max(res, area(a[i], a[j], a[k], a[l]));
                }
            }
        }
    }
    cout << fixed << setprecision(1) << res;
}
