#include <bits/stdc++.h>

using namespace std;

int ma[10000][10000];

int main() {
    int n;

    cin >> n;

    vector<int> ma[10000];

    for (int i = 0; i < n; i++) {
        string temp;

        getline(cin, temp);

        stringstream ss;

        ss >> temp;

        int num = stoi(ss.str());

        while (ss >> temp) {
            ma[num].push_back(stoi(ss.str()));
        }
    }

    for (int i = 1; i <= n; i++) {
        for (auto j : ma[i]) {
            cout << i << " " j << endl;
        }
    }
}
