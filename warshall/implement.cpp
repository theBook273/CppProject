#include <bits/stdc++.h>
#define int long long

using namespace std;

const int maxn(1e4 + 8);
int n, m, dem, res;
int id[maxn], low[maxn];
vector<int> a[maxn];
stack<int> tracker;

void dfs(int x) {
    id[x] = low[x] = ++dem;
    tracker.push(x);
    for (auto i : a[x]) {
        if (id[i] != 0) {
            low[x] = min(low[x], id[i]);
        } else {
            dfs(i);
            low[x] = min(low[x], low[i]);
        }
    }
    if (low[x] == id[x]) {
        ++res;
        while (!tracker.empty()) {
            id[tracker.top()] = low[tracker.top()] = 1e9;
            if (tracker.top() == x) {
                tracker.pop();
                break;
            }
            tracker.pop();
        }
    }
}

signed main() {
    cin.tie(NULL)->sync_with_stdio(false);
    cin >> n >> m;

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        a[u].push_back(v);
    }

    for (int i = 1; i <= n; ++i) {
        if (id[i] == 0) {
            dfs(i);
        }
    }

    cout << res << endl;
}