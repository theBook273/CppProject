#include <bits/stdc++.h>

using namespace std;
using ll = long long;

signed main() {
    int n;

    cin >> n;

    char s[n];
    string temp = "";
    vector<string> cut, s1, s2, s3;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
        temp.push_back(s[i]);
        if (s[i] == ',' || s[i] == ';') {
            temp.pop_back();
            if (temp != "") cut.push_back(temp);
            temp.clear();
        }
    }
    if (temp != "") cut.push_back(temp);

    for (auto i : cut) {
        bool check1 = 0, check2 = 0;
        for (auto j : i) {
            if (!isalpha(j)) check1 = 1;
            if (!isdigit(j)) check2 = 1;
        }
        if (!check1 && check2) s1.push_back(i);
        if (check1 && !check2) {
            if (i.size() > 1) {
                if (i[0] == '0')
                    s3.push_back(i);
                else
                    s2.push_back(i);
            } else
                s2.push_back(i);
        }
        if (check1 && check2) s3.push_back(i);
    }

    if (s1.empty()) cout << "-";
    for (auto i : s1) {
        cout << i << " ";
    }
    cout << endl;

    if (s2.empty()) cout << "-";
    for (auto i : s2) {
        cout << i << " ";
    }
    cout << endl;

    if (s3.empty()) cout << "-";
    for (auto i : s3) {
        cout << i << " ";
    }
}