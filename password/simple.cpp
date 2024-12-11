#include <bits/stdc++.h>
#define int long long

using namespace std;

int res = 0;
int lim = floor(sqrt(1e9)) + 1;
vector<int> prime;
string s;

void simpleSive(int n) {
    bool check[100009];
    memset(check, 1, sizeof(check));

    for (int i = 2; i * i <= n; i++) {
        if (check[i])
            for (int j = 2; j * i <= n; j++) check[i * j] = 0;
    }

    for (int i = 2; i <= n; i++) {
        if (check[i]) prime.push_back(i);
    }
}

bool segmentedSieve(int n) {}

signed main() {
    cin.tie(NULL)->sync_with_stdio(false);

    simpleSive(lim);

    cin >> s;
}