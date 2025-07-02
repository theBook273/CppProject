#include <bits/stdc++.h>
#define long long long long

using namespace std;
long long n, m, id[100000], low[100000], cnt, res;
vector<long long> v[100000];
stack<long long> st;

void tarjan(long long u) {
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
        long long temp;
        do {
            temp = st.top();
            st.pop();
            low[temp] = id[temp] = 1e9;
        } while (temp != u);
    }
}

signed main() {
    cin >> n >> m;
    for (long long i = 1; i <= m; i++) {
        long long a, b;
        cin >> a >> b;
        v[a].push_back(b);
    }
    for (long long i = 1; i <= n; i++) {
        if (!id[i]) tarjan(i);
    }

    cout << res;
}
