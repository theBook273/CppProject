#include <bits/stdc++.h>
#define int long long

using namespace std;

int n, k, xq, yq;
map<pair<int, int>, bool> mp;

int solveD(int x, int y, int n) {
    int tong = 0;
    int temp = x;
    while (temp < n) {
        temp++;
        if (mp[{temp, y}]) {
            break;
        }
        tong++;
    }
    temp = x;
    while (temp > 1) {
        temp--;
        if (mp[{temp, y}]) {
            break;
        }
        tong++;
    }
    return tong;
}

int solveN(int x, int y, int n) {
    int tong = 0;
    int temp = y;
    while (temp < n) {
        temp++;
        if (mp[{x, temp}]) {
            break;
        }
        tong++;
    }
    temp = y;
    while (temp > 1) {
        temp--;
        if (mp[{x, temp}]) {
            break;
        }
        tong++;
    }
    return tong;
}

int solveC(int x, int y, int n) {
    int tong = 0;
    int tempx = x, tempy = y;

    while (tempx > 1 && tempy > 1) {
        tempx--;
        tempy--;
        if (mp[{tempx, tempy}]) {
            break;
        }
        tong++;
    }

    tempx = x, tempy = y;
    while (tempx < n && tempy < n) {
        tempx++;
        tempy++;
        if (mp[{tempx, tempy}] || tempx > n || tempy > n) {
            break;
        }
        tong++;
    }

    tempx = x, tempy = y;
    while (tempx > 1 && tempy < n) {
        tempx--;
        tempy++;
        if (mp[{tempx, tempy}]) {
            break;
        }
        tong++;
    }

    tempx = x, tempy = y;
    while (tempx < n && tempy > 1) {
        tempx++;
        tempy--;
        if (mp[{tempx, tempy}]) {
            break;
        }
        tong++;
    }
    return tong;
}
main() {
    cin >> n >> k >> xq >> yq;

    for (int i = 0; i < k; i++) {
        int a, b;
        cin >> a >> b;
        mp[{a, b}] = 1;
    }

    int tong = solveD(xq, yq, n);
    tong += solveN(xq, yq, n);
    tong += solveC(xq, yq, n);

    cout << tong;
}