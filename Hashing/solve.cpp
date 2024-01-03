#include <bits/stdc++.h>

using namespace std;

string s;
int res = 0;
int n;

void findMax(int curSize) {
    unordered_map<string, int> dem;

    // cout << curSize << endl;
    // cout << s << endl;
    for (int i = 0; i < n; i++) {
        string temp;
        for (int j = i; j < i + curSize && j < n; j++) {
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
    int l = 0, r = s.size();
    int temp = res;

    while (l <= r) {
        int m = (l + r) / 2;
        findMax(m);
        if (res != temp) {
            l = m + 1;
        } else {
            r = m;
        }
    }
}

int main() {
    cin >> n;

    cin >> s;

    binCheck();

    cout << res;
}