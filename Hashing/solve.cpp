#include <bits/stdc++.h>

using namespace std;

string s;
long long res = 0;
long long n;

void findMax(long long curSize) {
    unordered_map<string, long long> dem;

    // cout << curSize << endl;
    // cout << s << endl;
    for (long long i = 0; i < n; i++) {
        string temp;
        for (long long j = i; j < i + curSize && j < n; j++) {
            temp += s[j];
        }
        dem[temp]++;
    }

    for (auto i : dem) {
        if (i.second >= 2 && res < i.first.size()) {
            res = i.first.size();
        }
        // cout << i.first << " " << i.second << endl;
    }
}

void binCheck() {
    long long l = 0, r = s.size();
    long long temp = res;

    while (l <= r) {
        long long m = (l + r) / 2;
        findMax(m);
        if (res != temp) {
            l = m + 1;
        } else {
            r = m;
        }
    }
}

long long main() {
    cin >> n;

    cin >> s;

    binCheck();

    cout << res;
}
