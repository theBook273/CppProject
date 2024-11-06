#include <bits/stdc++.h>
#define int long long

using namespace std;

bool res = 0;
int u, d;

void simpleSieve(vector<int> &prime, int last) {
    bool mark[last + 1];
    memset(mark, 1, sizeof(mark));

    for (int i = 2; i * i <= last; i++) {
        if (mark[i]) {
            for (int j = i * i; j <= last; j += i) {
                mark[j] = 0;
            }
        }
    }

    for (int i = 2; i <= last; i++) {
        if (mark[i]) {
            prime.push_back(i);
            if (d <= i && i <= u) {
                cout << i << "\n";
            }
        }
    }
}

void segmentedSieve(int n) {
    int lim = floor(sqrt(n)) + 1;
    vector<int> prime;
    simpleSieve(prime, lim);

    int l = floor(d / lim) * lim;
    int r = l + lim;

    while (l < n) {
        if (r >= n) r = n;

        bool mark[lim + 1];
        memset(mark, 1, sizeof(mark));

        for (int i : prime) {
            int loLim = floor(l / i) * i;
            if (loLim < l) loLim += i;

            for (int j = loLim; j <= r; j += i) {
                mark[j - l] = 0;
            }
        }

        for (int i = l; i <= r; i++) {
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
    int n;
    cin >> n;
    while (n--) {
        cin >> d >> u;
        segmentedSieve(u);
    }
}