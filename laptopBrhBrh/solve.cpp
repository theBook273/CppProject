#include <bits/stdc++.h>

using namespace std;

pair<string, long long> mp;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long n;
    cin >> n;

    for (long long i = 0; i < n; i++) {
        string temp;
        long long tong = 0;

        cin >> temp;

        for (int j = 0; j < temp.size(); j++) {
            tong += (temp[j] - '0');
        }

        if (tong == mp.second) {
            if (temp.size() < mp.first.size()) {
                continue;
            } else if (temp.size() == mp.first.size()) {
                if (temp > mp.first) {
                    mp.first = temp;
                    mp.second = tong;
                }
            } else {
                mp.first = temp;
                mp.second = tong;
            }
        } else if (tong > mp.second) {
            mp.first = temp;
            mp.second = tong;
        }
    }

    cout << mp.first << endl;
}
