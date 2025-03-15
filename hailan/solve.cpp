#include <bits/stdc++.h>

using namespace std;

string s;
int res = 0;
int n;

void findMax(int curSize) {
    unordered_map<string, int> dem;
    int hash = 0;

       for (int i = 0; i < n; i++) {
        string temp;
        for (int j = i; j < i + curSize && j < n; j++) {
            temp += s[j];
        }
        dem[temp]++;
        if (dem[temp] > 1) {
            res = max(res, curSize);
        }
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
