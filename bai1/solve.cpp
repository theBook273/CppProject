#include <bits/stdc++.h>
#define long long unsigned long long

using namespace std;

long long tong = 0;
long long n, res = 1e10 + 27;
vector<long long> temp;
bool flag = 0;

void build() {
    string s;
    for (auto a : temp) {
        for (long long i = 0; i < a; ++i) {
            s += to_string(a);
        }
    }

    if (stoull(s) > n) {
        res = min(res, stoull(s));
        flag = 1;
    } else {
        while (next_permutation(s.begin(), s.end())) {
            if (stoull(s) > n) {
                res = min(res, stoull(s));
                flag = 1;
                break;
            }
        }
    }
}

void gen(long long x, long long y) {
    if (tong == x) {
        build();
        return;
    }
    for (long long i = y; i <= x; ++i) {
        if (tong + i <= x) {
            tong += i;
            temp.push_back(i);
            gen(x, i + 1);
            tong -= i;
            temp.pop_back();
        }
    }
}

signed main() {
    cin >> n;

    gen(to_string(n).size(), 1);
    if (!flag) gen(to_string(n).size() + 1, 1);

    cout << res << endl;
}
