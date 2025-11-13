#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 27;

struct node {
  int data, index;
  node() {
    data = 0;
    index = 0;
  }
  node(int data, int index) {
    this->data = data;
    this->index = index;
  }
};

node max(node a, node b) {
  if (a.data > b.data) {
    return a;
  } else if (a.data == b.data) {
    if (a.index < b.index) {
      return a;
    } else {
      return b;
    }
  } else {
    return b;
  }
}

vector<node> st;
vector<int> a;

void build(int id, int l, int r) {
  if (l == r) {
    st[id] = node(a[l], l);
    return;
  }
  int m = (l + r) / 2;
  build(id * 2, l, m);
  build(id * 2 + 1, m + 1, r);
  st[id] = max(st[id * 2], st[id * 2 + 1]);
}

signed main() {}
