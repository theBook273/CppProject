#include <bits/stdc++.h>
#define long long long long

using namespace std;

long long lim = floor(sqrt(1e9)) + 1;
long long res = 0;
bool check[1000000];
vector<long long> prime;

bool primeCheck(long long x) {
    for (auto i : prime) {
        if (i <= x) {
            if (x % i == 0) {
                if (x == i) return 1;
                return 0;
            }
        } else
            break;
    }
    return 1;
}

signed main() {
    cin.tie(NULL)->sync_with_stdio(false);
    memset(check, 1, sizeof(check));

    for (long long i = 2; i * i <= lim; i++) {
        if (check[i]) {
            for (long long j = 2; j * i <= lim; j++) {
                check[j * i] = 0;
            }
        }
    }

    for (long long i = 2; i <= lim; i++) {
        if (check[i]) prime.push_back(i);
    }

    string s;
    cin >> s;

    for (long long i = 0; i < s.size(); i++) {
        if (!isalpha(s[i])) {
            string temp;
            for (long long j = i; j < s.size(); j++) {
                if (isalpha(s[j])) break;
                temp.push_back(s[j]);
                if (temp.size() <= 9) {
                    long long num = stoll(temp);
                    if (primeCheck(num)) {
                        res = max(res, num);
                    }
                }
            }
        }
    }

    cout << res;
}
