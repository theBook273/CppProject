#include <bits/stdc++.h>

using namespace std;

int main() {
    string se;

    set<string> ssm;

    string s;

    getline(cin, s);

    int r = 0;

    while (r < s.size()) {
        if (s[r] != ' ') {
            string temp;
            while (s[r + 1] != ' ' && r + 1 < s.size()) {
                temp.push_back(s[r]), r++;
            }
            temp.push_back(s[r]);
            int tempSize = ssm.size();
            ssm.insert(temp);

            if (tempSize != ssm.size()) {
                se += (temp + " ");
            }
        }
        r++;
    }

    string temp;

    for (auto i : ssm) {
        temp += (i + " ");
    }

    for (int i = 0; i < temp.size() - 1; i++) {
        cout << temp[i];
    }
    cout << endl;

    for (int i = 0; i < se.size() - 1; i++) {
        cout << se[i];
    }
}