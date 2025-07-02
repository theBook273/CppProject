#include <bits/stdc++.h>
#define long long long long

using namespace std;

vector<long long> a[1000], b[1000];

signed main() {
    long long n, m;
    cin >> n >> m;

    for (long long i = 0; i < n; i++) {
        long long v1, v2;
        cin >> v1 >> v2;
        a[v1].push_back(v2);
        b[v2].push_back(v1);
    }
}
