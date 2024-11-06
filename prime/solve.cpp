#include <bits/stdc++.h>
#define int long long

using namespace std;

int a[99999999];
int input[100000];

bool check(int n) {
    string s = to_string(n);
    string copied = s;

    if (s.size() < 2) return 0;

    while (!copied.empty()) {
        if (!a[stoi(copied)]) return 0;
        copied.pop_back();
    }

    string temp = "1379";
    int check = 0;

    for (auto i : temp) {
        s += i;
        if (a[stoi(s)]) check++;
        s.pop_back();
    }

    return check;
}
signed main() {
    cin.tie(NULL)->sync_with_stdio(false);
    memset(a, 1, sizeof(a));
    a[0] = a[1] = a[99999998] = 0;
    for (int i = 2; i < 99999999; i++)
        if (a[i])
            for (int j = 2; i * j < 99999999; j++) a[i * j] = 0;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> input[i];
    }

    int tong = 0;

    for (int i = 0; i < n; i++) {
        if (check(input[i])) {
            cout << input[i] << " ";
            tong += input[i];
        }
    }
    cout << "\n" << tong;
}