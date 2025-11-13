#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie()->sync_with_stdio(0);

    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a.rbegin(), a.rend());

    multiset<int> S;
    long long cost = 0;

    for (int x : a) {
        int low = x + k;
        auto it = S.lower_bound(low);
        if (it != S.end()) {
            S.erase(it);
        } else {
            cost += x;
        }
        S.insert(x);
    }

    cout << cost << endl;

    return 0;
}
