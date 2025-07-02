#include <bits/stdc++.h>

using namespace std;
using ll = long long;
vector<pair<long long, long long>> v;

bool comp(pair<long long, long long> a, pair<long long, long long> b) { return a.second < b.second; }

signed main() {
    long long n;
    cin >> n;

    for (long long i = 0; i < n; i++) {
        long long m;
        cin >> m;
        v.push_back({m, 0});
        for (long long j = 0; j < m; j++) {
            long long temp;
            cin >> temp;
            v.back().second = max(temp, v.back().second);
        }
    }

    sort(v.begin(), v.end(), comp);

    ll tong = 0;

    for (auto i : v) {
        tong += (v.back().second - i.second) * i.first;
    }
    cout << tong;
}
