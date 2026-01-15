#include "subSet.h"
#include <bits/stdc++.h>

using namespace std;

signed main() {
  Solution a;

  vector<long long> n = {1, 2, 3};

  vector<vector<long long>> res = a.combinationSum(n);

  for (auto i : res) {
    for (auto j : i) {
      cout << j << " ";
    }
    cout << endl;
  }

  return 0;
}
