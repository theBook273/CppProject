#include <bits/stdc++.h>
#define long long long long

using namespace std;

vector<pair<pair<long long, long long>, long long>> temp;
long long dsu[999999], val[999999], tong = 0, tar = 1;
map<pair<long long, long long>, long long> mp;

long long parent(long long x) {
    if (x == dsu[x]) return x;
    return dsu[x] = parent(dsu[x]);
}

void join(long long x, long long y) {
    x = parent(x);
    y = parent(y);
    if (x != y) {
        if (val[x] > val[y]) swap(x, y);
        dsu[x] = y;
    }
}

bool comp(pair<pair<long long, long long>, long long> a, pair<pair<long long, long long>, long long> b) {
    return a.second < b.second;
}

main() {
    long long n, m;

    cin >> n >> m;

    for (long long i = 1; i <= n; i++) {
        cin >> val[i];
        dsu[i] = i;
        if (val[tar] > val[i]) tar = i;
    }

    for (long long i = 1; i <= n; i++) {
        if (parent(i) != tar) {
            temp.push_back({{tar, i}, val[i] + val[tar]});
        }
    }

    for (long long i = 1; i <= m; i++) {
        long long a, b, x;
        cin >> a >> b >> x;
        if (val[a] > val[b]) swap(a, b);
        temp.push_back({{a, b}, x});
    }

    sort(temp.begin(), temp.end(), comp);

    for (auto i : temp) {
        if (parent(i.first.first) != parent(i.first.second)) {
            join(i.first.first, i.first.second);
            tong += i.second;
        }
    }
    cout << tong;
}
