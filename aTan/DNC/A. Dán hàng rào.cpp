#include <bits/stdc++.h>
#define int long long

using namespace std;

const int oo = 1e18;

int n;
vector<int> a;

int dnc(int l, int r) {
  if (l > r) {
    return 0;
  }

  int mini = oo;
  for (int i = l; i <= r; i++) {
    mini = min(a[i], mini);
  }

  int mid = 0;
  for (int i = l; i <= r; i++) {
    if (a[i] == mini) {
      mid = i;
    }
    a[i] -= mini;
  }

  return dnc(l, mid - 1) + dnc(mid + 1, r) + (mini != 0);
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n;
  a.resize(n);

  for (auto &i : a) {
    cin >> i;
  }

  cout << dnc(0, n - 1);
}
