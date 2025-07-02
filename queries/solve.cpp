#include <bits/stdc++.h>

using namespace std;

long long n, d, arr[1000000], queries;

void check(deque<long long> temp) {
    for (auto i : temp) {
        cout << i << " ";
    }
}

long long main() {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    cin >> n >> d;

    for (long long i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for (long long i = 0; i < d; i++) {
        cin >> queries;

        long long res = 1e9, r = 0;
        deque<long long> a;

        for (long long j = 0; j < n; j++) {
            while (!a.empty() && arr[a.back()] < arr[j]) {
                a.pop_back();
            }

            a.push_back(j);

            while (!a.empty() && a.front() <= j - queries) {
                a.pop_front();
            }

            if (j - queries >= -1 && !a.empty()) {
                res = min(res, arr[a.front()]);
            }
        }

        cout << res << endl;
    }
}
