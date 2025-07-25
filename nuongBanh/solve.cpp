#include <bits/stdc++.h>
using namespace std;

const int MAXN = 40005;
int N, D;
vector<long long> A(MAXN);

struct Node {
  long long f0,
      f1; // f0: không chọn lò cuối, f1: chọn lò cuối (không chọn áp cuối)
};

vector<Node> tree(MAXN * 4);
vector<long long> last_val(MAXN, 0); // Lưu giá trị tại lá để truy cập khi gộp

Node merge(const Node &left, const Node &right, int mid) {
  Node res;
  // Không chọn lò cuối của đoạn phải
  res.f0 = max(left.f0 + right.f0, left.f1 + right.f0);
  // Chọn lò cuối của đoạn phải (không chọn lò áp cuối)
  res.f1 = left.f0 + right.f1;
  // Nếu mid là lò áp cuối, có thể chọn mid thay vì lò cuối đoạn phải
  if (mid >= 1) {
    res.f1 = max(res.f1, left.f0 + last_val[mid]);
  }
  return res;
}

void build(int id, int l, int r) {
  if (l == r) {
    tree[id].f0 = 0;    // Không chọn lò l
    tree[id].f1 = A[l]; // Chọn lò l
    last_val[l] = A[l]; // Lưu giá trị tại lá
    return;
  }
  int mid = (l + r) / 2;
  build(id * 2, l, mid);
  build(id * 2 + 1, mid + 1, r);
  tree[id] = merge(tree[id * 2], tree[id * 2 + 1], mid);
}

void update(int id, int l, int r, int pos, long long val) {
  if (l == r) {
    tree[id].f0 = 0;
    tree[id].f1 = val;
    last_val[l] = val;
    return;
  }
  int mid = (l + r) / 2;
  if (pos <= mid)
    update(id * 2, l, mid, pos, val);
  else
    update(id * 2 + 1, mid + 1, r, pos, val);
  tree[id] = merge(tree[id * 2], tree[id * 2 + 1], mid);
}

long long query() { return max(tree[1].f0, tree[1].f1); }

int main() {

  cin >> N >> D;
  for (int i = 1; i <= N; i++) {
    cin >> A[i];
  }

  build(1, 1, N);

  long long total = 0;
  for (int day = 1; day <= D; day++) {
    int pos, val;
    cin >> pos >> val;
    A[pos] = val;
    update(1, 1, N, pos, val);
    total += query();
  }

  cout << total << endl;
  return 0;
}
