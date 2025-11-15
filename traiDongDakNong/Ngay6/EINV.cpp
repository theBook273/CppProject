#include<bits/stdc++.h>
#define int long long

using namespace std;

class SegTree {
private:
    vector<int> st;

public:
    SegTree(int x) {
        st.resize(x * 4 + 5);
    }

    void update(int l, int r, int pos,int x, int id) {
        if(l == r) {
            st[id] += x;
            return;
        }
        int m((l + r) / 2);
        if(pos <= m) {
            update(l, m, pos, x, id << 1);
        } else {
            update(m + 1, r, pos, x, id << 1 | 1);
        }
        st[id] = st[id << 1] + st[id << 1 | 1];
    }

    int query(int l, int r, int u, int v, int id) {
        if(l > r || l > v || u > r) {
            return 0;
        }
        if(u <= l && r <= v) {
            return st[id];
        }
        int m((l + r) / 2);
        return query(l, m, u, v, id << 1) + query(m + 1, r, u, v, id << 1 | 1);
    }
};

vector<int> a, ins, des;
int n, m, k;

void compress() {
    vector<int> val = a;
    sort(val.begin(), val.end());
    val.erase(unique(val.begin(), val.end()), val.end());
    for(auto &i : a) {
        i = lower_bound(val.begin(), val.end(), i) - val.begin() + 1;
    }
    m = val.size();
}

signed main() {
    cin.tie()->sync_with_stdio(0);

//    freopen("test.inp", "r", stdin);
//    freopen("test.out", "w", stdout);

    cin >> n >> k;
    a.resize(n), ins.resize(n), des.resize(n);

    for(auto &i : a) {
        cin >> i;
    }

    compress();

}
