#include <bits/stdc++.h>
#define long long long long

using namespace std;

void simpleSieve(vector<long long> &prime, long long lim) {
    bool check[lim + 1];
    memset(check, 1, sizeof(check));

    check[0] = check[1] = 0;

    for (long long i = 2; i * i <= lim; i++)
        if (check[i])
            for (long long j = i * i; j <= lim; j += i) check[j] = 0;

    for (long long i = 2; i <= lim; i++) {
        if (check[i]) {
            cout << i << ", ";
            prime.push_back(i);
        }
    }
}

void segmentedSieve(long long n) {
    long long lim = floor(sqrt(n)) + 1;
    vector<long long> prime;

    simpleSieve(prime, lim);

    long long l = lim;
    long long r = lim * 2;

    while (l <= n) {
        if (r > n) r = n;
        bool mark[lim + 1];
        memset(mark, 1, sizeof(mark));

        for (long long i : prime) {
            long long loLim = floor(l / i) * i;
            if (loLim < l) loLim += i;
            for (long long j = loLim; j <= r; j += i) mark[j - l] = 0;
        }

        for (long long i = l; i <= r; i++)
            if (mark[i - l] == 1) cout << i << ", ";

        l += lim;
        r += lim;
    }
}

signed main() {
    cin.tie(NULL)->sync_with_stdio(false);
    long long n;
    cin >> n;
    segmentedSieve(n);
}
