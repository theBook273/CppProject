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

        deque<long long> a;
        long long minRes = 1e9, subMax = 0, tempMax, r = 0;

        for (long long j = 0; j < n; j++) {
            if (j - r + 1 <= queries) {
            }
            if (j - r + 1 == queries) {
                minRes = min(minRes, subMax);

                subMax = 0;

                r++;
            }
        }

        cout << minRes << endl;
    }
}
