#include <bits/stdc++.h>

using namespace std;
long long n, k, a[100000], tong = 0;
vector<long long> s;
vector<vector<long long>> res;

void duyet(long long x) {
    if (tong == k) {
        sort(s.begin(), s.end());
        res.push_back(s);
        return;
    }

    for (long long i = x + 1; i < n; i++) {
        if (tong + a[i] <= k) {
            tong += a[i];
            s.push_back(a[i]);
            duyet(i);
            tong -= a[i];
            s.pop_back();
        }
    }
}

long long main() {
    cin >> n >> k;
    for (long long i = 0; i < n; i++) {
        cin >> a[i];
    }

    duyet(0);

    sort(res.begin(), res.end());

    for (auto i : res) {
        cout << "[";
        for (long long j = 0; j < i.size(); j++) {
            cout << i[j];
            if (j + 1 < i.size()) cout << " ";
        }

        cout << "]" << endl;
    }
}
