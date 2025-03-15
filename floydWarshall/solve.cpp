#include <bits/stdc++.h>
#define int long long

using namespace std;

vector<int> a[1000], b[1000];

signed main() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        int v1, v2;
        cin >> v1 >> v2;
        a[v1].push_back(v2);
        b[v2].push_back(v1);
    }
}