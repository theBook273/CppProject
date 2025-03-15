#include <bits/stdc++.h>

using namespace std;
using ll = long long;

vector<pair<char, ll>> v;
vector<char> maxIn, minIn;

void linked(vector<pair<char, ll>> cont) {
    string res = "";
    char lastW = cont[0].first;
    for (auto &i : cont) {
        if (i.second == 0) {
            i.first = '0';
        }
    }

    for (ll i = 0; i < cont.size(); i++) {
        if (cont[i].first == '0') {
            if (cont[i + 1].first != '0' && cont[i + 1].second != 0 &&
                cont[i - 1].first == cont[i + 1].first) {
                cont[i - 1].second += cont[i + 1].second;
                cont[i + 1].first = '0';
            }
        }
    }
    for (auto i : cont) {
        if (i.first == '0') {
            continue;
        }
        cout << i.first << i.second;
    }
}
void maximize(int k, vector<pair<char, ll>> v) {
    while (k != 0) {
        for (auto &i : v) {
            if (i.first == minIn.back()) {
                if (i.second >= k) {
                    i.second -= k;
                    k = 0;
                } else {
                    k -= i.second;
                    i.second = 0;
                }
            }
        }
        minIn.pop_back();
    }
    linked(v);
}

void minimize(int k, vector<pair<char, ll>> v) {
    while (k != 0) {
        for (auto &i : v) {
            if (i.first == maxIn.back()) {
                if (i.second >= k) {
                    i.second -= k;
                    k = 0;
                } else {
                    k -= i.second;
                    i.second = 0;
                }
            }
        }
        maxIn.pop_back();
    }
    linked(v);
}

void solve(string s, int k) {
    for (ll i = 0; i < s.size(); i++) {
        string temp = "";
        if (isalpha(s[i])) {
            maxIn.push_back(s[i]);
            minIn.push_back(s[i]);
            v.push_back({s[i], 0});
            while (i + 1 < s.size() && !isalpha(s[i + 1])) {
                i++;
                temp += s[i];
            }
        }
        v[v.size() - 1].second += stoll(temp);
    }

    sort(maxIn.begin(), maxIn.end());
    sort(minIn.begin(), minIn.end(), greater<char>());
    maximize(k, v);
    cout << endl;
    minimize(k, v);
}

signed main() {
    ll k;
    string s;

    cin >> k >> s;

    solve(s, k);
}