#include <bits/stdc++.h>
#define endl '\n'
#define int long long

using namespace std;

double area(pair<int, int> a, pair<int, int> b, pair<int, int> c,
            pair<int, int> d) {
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
    int n;
    cin >> n;
    pair<int, int> a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
    }
    double res(0);
    for (int i = 0; i < n - 4; ++i) {
        for (int j = i + 1; j < n; ++j) {
            for (int k = j + 1; k < n; ++k) {
                for (int l = k + 1; l < n; ++l) {
                    res = max(res, area(a[i], a[j], a[k], a[l]));
                }
            }
        }
    }
    cout << fixed << setprecision(1) << res;
}