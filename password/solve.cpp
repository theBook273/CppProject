#include <bits/stdc++.h>
#define int long long

using namespace std;

int lim = floor(sqrt(1e9)) + 1;
int res = 0;
bool check[1000000];
vector<int> prime;

bool primeCheck(int x) {
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

    for (int i = 2; i * i <= lim; i++) {
        if (check[i]) {
            for (int j = 2; j * i <= lim; j++) {
                check[j * i] = 0;
            }
        }
    }

    for (int i = 2; i <= lim; i++) {
        if (check[i]) prime.push_back(i);
    }

    string s;
    cin >> s;

    for (int i = 0; i < s.size(); i++) {
        if (!isalpha(s[i])) {
            string temp;
            for (int j = i; j < s.size(); j++) {
                if (isalpha(s[j])) break;
                temp.push_back(s[j]);
                if (temp.size() <= 9) {
                    int num = stoll(temp);
                    if (primeCheck(num)) {
                        res = max(res, num);
                    }
                }
            }
        }
    }

    cout << res;
}