#include <bits/stdc++.h>

using namespace std;

long long parent[10000], dem;
vector<pair<long long, long long>> repeatOnes;

void initU(long long n) {
    for (long long i = 1; i <= n; i++) {
        parent[i] = i;
    }
}

long long find(long long a) {
    if (parent[a] == a) return a;
    return parent[a] = find(parent[a]);
}

void makeU(long long a, long long b) {
    repeatOnes.push_back({a, b});
    a = find(a);
    b = find(b);

    if (a != b) {
        parent[b] = a;
        dem--;
        repeatOnes.pop_back();
    }
}

int main() {
    long long n;

    cin >> n;

    dem = n;

    initU(n);

    for (long long i = 1; i < n; i++) {
        long long a, b;

        cin >> a >> b;

        makeU(a, b);
    }

    dem--;

    if (dem == 0) {
        cout << dem;
        return 0;
    }

    cout << dem << endl;
    for (auto v : repeatOnes) {
        cout << v.first << " " << v.second << " ";

        long long a1 = find(v.second), b1;

        for (long long i = 1; i <= n; i++) {
            if (parent[i] == i && i != a1) {
                b1 = i;
                break;
            }
        }

        makeU(a1, b1);
        // cout << endl;

        // for (int i = 1; i <= n; i++) {
        //     cout << i << " " << parent[i] << " | ";
        // }

        // cout << endl;

        cout << a1 << " " << b1 << endl;
    }
}