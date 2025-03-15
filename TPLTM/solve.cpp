#include <bits/stdc++.h>
#define int long long

using namespace std;
int n, m, id[100000], low[100000], cnt, res;
vector<int> v[100000];
stack<int> st;

void tarjan(int u) {
    id[u] = low[u] = ++cnt;
    st.push(u);
    for (auto i : v[u]) {
        if (id[i])
            low[u] = min(low[u], id[i]);
        else {
            tarjan(i);
            low[u] = min(low[u], low[i]);
        }
    }
    if (low[u] == id[u]) {
        res++;
        int temp;
        do {
            temp = st.top();
            st.pop();
            low[temp] = id[temp] = 1e9;
        } while (temp != u);
    }
}

signed main() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
    }
    for (int i = 1; i <= n; i++) {
        if (!id[i]) tarjan(i);
    }

    cout << res;
}