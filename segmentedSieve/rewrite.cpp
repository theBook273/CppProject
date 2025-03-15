#include <bits/stdc++.h>
#define int long long

using namespace std;

void simpleSieve(vector<int> &prime, int lim) {
    bool check[lim + 1];
    memset(check, 1, sizeof(check));

    check[0] = check[1] = 0;

    for (int i = 2; i * i <= lim; i++)
        if (check[i])
            for (int j = i * i; j <= lim; j += i) check[j] = 0;

    for (int i = 2; i <= lim; i++) {
        if (check[i]) {
            cout << i << ", ";
            prime.push_back(i);
        }
    }
}

void segmentedSieve(int n) {
    int lim = floor(sqrt(n)) + 1;
    vector<int> prime;

    simpleSieve(prime, lim);

    int l = lim;
    int r = lim * 2;

    while (l <= n) {
        if (r > n) r = n;
        bool mark[lim + 1];
        memset(mark, 1, sizeof(mark));

        for (int i : prime) {
            int loLim = floor(l / i) * i;
            if (loLim < l) loLim += i;
            for (int j = loLim; j <= r; j += i) mark[j - l] = 0;
        }

        for (int i = l; i <= r; i++)
            if (mark[i - l] == 1) cout << i << ", ";

        l += lim;
        r += lim;
    }
}

signed main() {
    cin.tie(NULL)->sync_with_stdio(false);
    int n;
    cin >> n;
    segmentedSieve(n);
}