#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll a[3][3], standard = 0;

ll tongNgang(ll a[3][3]) {
    ll tong = 0;
    for (int i = 0; i < 3; i++) {
        ll temp = 0;
        for (int j = 0; j < 3; j++) {
            temp += a[i][j];
        }
        tong = max(tong, temp);
    }
    return tong;
}

ll tongDoc(ll a[3][3]) {
    ll tong = 0;
    for (int i = 0; i < 3; i++) {
        ll temp = 0;
        for (int j = 0; j < 3; j++) {
            temp += a[j][i];
        }
        tong = max(tong, temp);
    }
    return tong;
}

ll tongCheo(ll a[3][3]) {
    ll tong = 0, temp = 0;
    for (int i = 0, j = 0; i < 3 && j < 3; j++, i++) {
        temp += a[i][j];
    }
    tong = max(tong, temp);

    temp = 0;

    for (int i = 0, j = 2; i < 3 && j >= 0; i++, j--) {
        temp += a[i][j];
    }

    tong = max(tong, temp);

    return tong;
}

void solveNgang(ll a[3][3]) {
    for (int i = 0; i < 3; i++) {
        pair<int, int> pos = {-1, -1};
        ll tong = 0;
        for (int j = 0; j < 3; j++) {
            if (a[i][j] == 0) pos = {i, j};
            tong += a[i][j];
        }
        if (pos.first != -1) {
            a[pos.first][pos.second] = standard - tong;
        }
    }
}

void solveDoc(ll a[3][3]) {
    for (int i = 0; i < 3; i++) {
        pair<int, int> pos = {-1, -1};
        ll tong = 0;
        for (int j = 0; j < 3; j++) {
            if (a[j][i] == 0) pos = {j, i};
            tong += a[j][i];
        }
        if (pos.first != -1) {
            a[pos.first][pos.second] = standard - tong;
        }
    }
}

void solveCheoTrai(ll a[3][3]) {
    pair<int, int> pos = {-1, -1};
    ll tong = 0;
    for (int i = 0, j = 0; i < 3 && j < 3; i++, j++) {
        if (a[i][j] == 0) pos = {i, j};
        tong += a[i][j];
    }

    a[pos.first][pos.second] = standard - tong;
}

void solveCheoPhai(ll a[3][3]) {
    pair<int, int> pos = {-1, -1};
    ll tong = 0;
    for (int i = 0, j = 2; i < 3 && j >= 0; i++, j--) {
        if (a[i][j] == 0) pos = {i, j};
        tong += a[i][j];
    }

    a[pos.first][pos.second] = standard - tong;
}

bool checkNgang(ll a[3][3]) {
    ll tong = 0;
    for (int i = 0; i < 3; i++) {
        ll temp = 0;
        for (int j = 0; j < 3; j++) {
            if (a[i][j] == 0) temp++;
        }
        tong = max(tong, temp);
    }
    return tong == 1;
}

bool checkDoc(ll a[3][3]) {
    ll tong = 0;
    for (int i = 0; i < 3; i++) {
        ll temp = 0;
        for (int j = 0; j < 3; j++) {
            if (a[j][i] == 0) temp++;
        }
        tong = max(tong, temp);
    }
    return tong == 1;
}

bool checkCheoTrai(ll a[3][3]) {
    ll tong = 0;
    ll temp = 0;
    for (int i = 0, j = 0; i < 3 && j < 3; i++, j++) {
        if (a[i][j] == 0) temp++;
    }

    tong = max(temp, tong);

    if (tong == 3) {
        ll sumRow[3] = {0, 0, 0};

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                sumRow[i] += a[i][j];
            }
        }

        a[0][0] = (sumRow[2] + (sumRow[1] - sumRow[0])) / 2;
        a[1][1] = (sumRow[2] - (sumRow[1] - sumRow[0])) / 2;
        a[2][2] = sumRow[1] - a[0][0];

        return 0;
    }

    return tong == 1;
}

bool checkCheoPhai(ll a[3][3]) {
    ll tong = 0;
    ll temp = 0;

    for (int i = 0, j = 2; i < 3 && j >= 0; i++, j--) {
        if (a[i][j] == 0) temp++;
    }

    tong = max(tong, temp);

    if (tong == 3) {
        ll sumRow[3] = {0, 0, 0};

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                sumRow[i] += a[i][j];
            }
        }

        a[0][2] = (sumRow[2] + (sumRow[1] - sumRow[0])) / 2;
        a[1][1] = (sumRow[2] - (sumRow[1] - sumRow[0])) / 2;
        a[2][0] = sumRow[1] - a[0][2];

        return 0;
    }

    return tong == 1;
}

signed main() {
    freopen("HVDEP.INP", "r", stdin);
    freopen("HVDEP.OUT", "w", stdout);

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> a[i][j];
        }
    }

    standard = max(tongCheo(a), max(tongDoc(a), tongNgang(a)));

    checkCheoPhai(a);
    checkCheoTrai(a);

    if (checkCheoPhai(a)) {
        solveCheoPhai(a);
    } else if (checkCheoTrai(a)) {
        solveCheoTrai(a);
    }
    if (checkDoc(a)) {
        solveDoc(a);
    } else if (checkNgang(a)) {
        solveNgang(a);
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}
