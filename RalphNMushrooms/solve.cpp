#include <bits/stdc++.h>

using namespace std;

const long long maxn = 1e6 + 8;

long long n, m, s, num[maxn], low[maxn], dem, res;
vector<long long> a[maxn];
stack<long long> st;
stack<pair<long long, long long>> mus;
vector<long long> road[1000][1000];

long long csc(long long x) {
    long long res = (2 + (x - 1)) * x;
    res /= 2;
    return res;
}

long long pick(long long x) {
    long long dem = 1;
    long long tong = x;
    while (x - csc(dem) >= 0) {
        tong += x - csc(dem);
        dem++;
    }
    return tong;
}

void tarjan(long long current, long long x) {
    if (current != -1) {
        mus.push({current, x});
    }
    st.push(x);
    num[x] = low[x] = ++dem;
    for (auto i : a[x]) {
        if (num[i] != 0) {
            low[x] = min(low[x], num[i]);
            mus.push({x, i});
        } else {
            tarjan(x, i);
            low[x] = min(low[x], low[i]);
        }
    }

    vector<long long> load;

    if (num[x] == low[x]) {
        map<long long, long long> check;
        long long temp;
        do {
            temp = st.top();
            check[temp]++;
            st.pop();
            low[temp] = num[temp] = 1e9;
        } while (temp != x);

        if (check.size() > 1) {
            // for (auto i : check) {
            //     cout << i.first << " ";
            // }
            // cout << endl;
            do {
                cout << mus.top().first << " " << mus.top().second << endl;
                for (auto r : road[mus.top().first][mus.top().second]) {
                    res += pick(r);
                }
                mus.pop();
            } while (check[mus.top().first] && check[mus.top().second]);
        } else {
            for (auto r : road[mus.top().first][mus.top().second]) {
                res += r;
            }
            mus.pop();
        }
    }
}

long long main() {
    cin >> n >> m;
    for (long long i = 0; i < m; i++) {
        long long x, y, z;
        cin >> x >> y >> z;
        a[x].push_back(y);
        road[x][y].push_back(z);
    }
    cin >> s;

    tarjan(-1, s);

    cout << res << endl;
}
