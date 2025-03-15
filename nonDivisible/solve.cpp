#include <bits/stdc++.h>
#define int long long

using namespace std;
int n, k, res, a[100000];
vector<int> v;

void chose(int x, int lim) {
    if (v.size() == lim) {
        for (int i = 0; i < v.size(); ++i) {
            for (int j = i + 1; j < v.size(); ++j) {
                if ((v[i] + v[j]) % k == 0) {
                    return;
                }
            }
        }
        res = max(res, lim);
        return;
    }
    for (int i = x + 1; i < n; ++i) {
        v.push_back(a[i]);
        chose(i, lim);
        v.pop_back();
    }
}

main() {
    cin >> n >> k;

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    for (int i = 1; i <= n; ++i) {
        chose(-1, i);
    }

    cout << res;
}