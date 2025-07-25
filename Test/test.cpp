#include <bits/stdc++.h>

using namespace std;

vector<int> a;
int dem = 0;
map<int, int> mp;

void build(int tong) {
  if (a.size() == 4 && tong == 13 && a.back() == 2 && mp[3] >= 1 &&
      mp[6] >= 1 && a.front() == 6) {
    dem++;
    for (auto i : a)
      cout << i;
    cout << "\n";
    return;
  }
  for (int i = 0; i <= 9; i++) {
    if (tong + i <= 13 && a.size() + 1 <= 4) {
      tong += i;
      mp[i]++;
      a.push_back(i);
      build(tong);
      tong -= i;
      mp[i]--;
      a.pop_back();
    }
  }
}

signed main() {
  build(0);
  cout << dem << "\n";
}
