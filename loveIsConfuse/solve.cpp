#include <bits/stdc++.h>

using namespace std;
vector<int> a[100000];
bool check[100000];
set<int> s;

bool dfs(int start, int now) {
    int temp = s.size();

    s.insert(a[now][0]);

    // cout << start << " " << a[now][0] << endl;

    if (s.size() == temp && a[now][0] == start)
        return 1;

    else if (s.size() == temp && a[now][0] != start)
        return 0;

    return dfs(start, a[now][0]);
}

int main() {
    int n, tong = 0;

    cin >> n;

    for (int i = 1; i <= n; i++) {
        int temp;

        cin >> temp;

        a[i].push_back(temp);
    }

    for (int i = 1; i <= n; i++) {
        s.clear();
        s.insert(i);
        check[i] = dfs(i, i);
    }

    for (int i = 1; i <= n; i++) {
        if (check[i] == 0) {
            tong++;
        }
    }

    cout << tong << endl;
}