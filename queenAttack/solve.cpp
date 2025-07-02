#include <bits/stdc++.h>
#define long long long long

using namespace std;

long long n, k, xq, yq;
map<pair<long long, long long>, bool> mp;

long long solveD(long long x, long long y, long long n) {
    long long tong = 0;
    long long temp = x;
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

long long solveN(long long x, long long y, long long n) {
    long long tong = 0;
    long long temp = y;
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

long long solveC(long long x, long long y, long long n) {
    long long tong = 0;
    long long tempx = x, tempy = y;

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

    for (long long i = 0; i < k; i++) {
        long long a, b;
        cin >> a >> b;
        mp[{a, b}] = 1;
    }

    long long tong = solveD(xq, yq, n);
    tong += solveN(xq, yq, n);
    tong += solveC(xq, yq, n);

    cout << tong;
}
