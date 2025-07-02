#include <bits/stdc++.h>
#define long long long long

using namespace std;

const long long maxn = 5 * 1e5 + 8;

long long a[maxn], mark[maxn];
long long n;

main() {
    cin >> n;
    for (long long i = 0; i < n; i++) {
        cin >> a[i];
    }

    long long res = 0;
    for (long long i = 0; i < n; i++) {
        long long maxnow = 0;
        for (long long j = i + 1; j < n; j++) {
            if (i + 1 == j) {
                res++;
            } else {
                maxnow = max(maxnow, a[j - 1]);
                if (a[i] < maxnow || a[j] < maxnow) {
                    break;
                } else
                    res++;
            }
        }
    }
    cout << res << endl;
}
