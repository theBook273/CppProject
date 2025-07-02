#include <bits/stdc++.h>

using namespace std;
vector<long long> a[100000];
bool check[100000];
set<long long> s;

bool dfs(long long start, long long now) {
    long long temp = s.size();

    s.insert(a[now][0]);

    // cout << start << " " << a[now][0] << endl;

    if (s.size() == temp && a[now][0] == start)
        return 1;

    else if (s.size() == temp && a[now][0] != start)
        return 0;

    return dfs(start, a[now][0]);
}

long long main() {
    long long n, tong = 0;

    cin >> n;

    for (long long i = 1; i <= n; i++) {
        long long temp;

        cin >> temp;

        a[i].push_back(temp);
    }

    for (long long i = 1; i <= n; i++) {
        s.clear();
        s.insert(i);
        check[i] = dfs(i, i);
    }

    for (long long i = 1; i <= n; i++) {
        if (check[i] == 0) {
            tong++;
        }
    }

    cout << tong << endl;
}
