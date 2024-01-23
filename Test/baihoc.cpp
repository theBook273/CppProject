#include <bits/stdc++.h>

using namespace std;

vector<int> v[1000000];
int cnt = 1;
int res[10000000];
bool visited[10000000];

void dfs(int x) {
    for (int i : v[x]) {
        if (!visited[i]) {
            cnt++;
            res[i] = res[x] + 1;
            visited[i] = 1;
            dfs(i);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int a, b, c;

        cin >> a >> b >> c;

        v[a].push_back(b);
        v[a].push_back(c);
    }

    res[1] = 1;
    dfs(1);

    for (int i = 1; i <= n; i++) {
        cout << res[i] << endl;
    }
}