#include <bits/stdc++.h>

using namespace std;
using ll = long long;
bool check1(pair<pair<ll, ll>, ll> a, pair<pair<ll, ll>, ll> b) {
    return a.first.second > b.first.second;
}

bool check2(pair<pair<ll, ll>, ll> a, pair<pair<ll, ll>, ll> b) {
    return a.second < b.second;
}

pair<pair<ll, ll>, ll> mlAndSpc[100000];

ll n, tong = 0, tongAni = 0;

void inp() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> mlAndSpc[i].first.first >> mlAndSpc[i].first.second;
        mlAndSpc[i].second = i;
        tongAni += mlAndSpc[i].first.first;
    }
}

void solve() {
    sort(mlAndSpc, mlAndSpc + n, check1);
    for (int i = 0; i < n; i++) {
        if (tongAni == 0) tong++;
        if (tongAni >= mlAndSpc[i].first.second) {
            mlAndSpc[i].first.first = mlAndSpc[i].first.second;
            tongAni -= mlAndSpc[i].first.second;
        } else if (tongAni < mlAndSpc[i].first.second) {
            mlAndSpc[i].first.first = tongAni;
            tongAni = 0;
        }
    }
    sort(mlAndSpc, mlAndSpc + n, check2);
}

void printAni() {
    solve();
    cout << tong << endl;
    for (int i = 0; i < n; i++) {
        cout << mlAndSpc[i].first.first << " ";
    }
}

int main() {
    inp();
    printAni();
}