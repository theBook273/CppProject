#include <bits/stdc++.h>
#define long long long long

using namespace std;

long long res = 0;
long long lim = floor(sqrt(1e9)) + 1;
vector<long long> prime;
string s;

void simpleSive(long long n) {
    bool check[100009];
    memset(check, 1, sizeof(check));

    for (long long i = 2; i * i <= n; i++) {
        if (check[i])
            for (long long j = 2; j * i <= n; j++) check[i * j] = 0;
    }

    for (long long i = 2; i <= n; i++) {
        if (check[i]) prime.push_back(i);
    }
}

bool segmentedSieve(long long n) {}

signed main() {
    cin.tie(NULL)->sync_with_stdio(false);

    simpleSive(lim);

    cin >> s;
}
