#include <bits/stdc++.h>
#define long long long long

using namespace std;

bool res = 0;
long long u, d;

void simpleSieve(vector<long long> &prime, long long last) {
    bool mark[last + 1];
    memset(mark, 1, sizeof(mark));

    for (long long i = 2; i * i <= last; i++) {
        if (mark[i]) {
            for (long long j = i * i; j <= last; j += i) {
                mark[j] = 0;
            }
        }
    }

    for (long long i = 2; i <= last; i++) {
        if (mark[i]) {
            prime.push_back(i);
            if (d <= i && i <= u) {
                cout << i << "\n";
            }
        }
    }
}

void segmentedSieve(long long n) {
    long long lim = floor(sqrt(n)) + 1;
    vector<long long> prime;
    simpleSieve(prime, lim);

    long long l = floor(d / lim) * lim;
    long long r = l + lim;

    while (l < n) {
        if (r >= n) r = n;

        bool mark[lim + 1];
        memset(mark, 1, sizeof(mark));

        for (long long i : prime) {
            long long loLim = floor(l / i) * i;
            if (loLim < l) loLim += i;

            for (long long j = loLim; j <= r; j += i) {
                mark[j - l] = 0;
            }
        }

        for (long long i = l; i <= r; i++) {
            if (mark[i - l]) {
                if (d <= i && i <= u) {
                    cout << i << "\n";
                }
            }
        }

        l += lim;
        r += lim;
    }
}

signed main() {
    cin.tie(NULL)->sync_with_stdio(false);
    long long n;
    cin >> n;
    while (n--) {
        cin >> d >> u;
        segmentedSieve(u);
    }
}
