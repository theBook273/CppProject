#include <bits/stdc++.h>

using namespace std;
using ll = long long;
vector<pair<int, int>> v;

bool comp(pair<int, int> a, pair<int, int> b) { return a.second < b.second; }

signed main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int m;
        cin >> m;
        v.push_back({m, 0});
        for (int j = 0; j < m; j++) {
            int temp;
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