#include <bits/stdc++.h>
#define int unsigned long long

using namespace std;

int tong = 0;
int n, res = 1e10 + 27;
vector<int> temp;
bool flag = 0;

void build() {
    string s;
    for (auto a : temp) {
        for (int i = 0; i < a; ++i) {
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

void gen(int x, int y) {
    if (tong == x) {
        build();
        return;
    }
    for (int i = y; i <= x; ++i) {
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
