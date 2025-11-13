#include "threeSum.h"
#include <bits/stdc++.h>

using namespace std;

int main() {
  Solution a;

  vector<long long> b = {-1, 0, 1, 2, -1, -4};

  vector<vector<long long>> v = a.threeSum(b);

  for (long long i = 0; i < v.size(); i++) {
    for (long long j = 0; j < v[i].size(); j++) {
      cout << v[i][j] << " ";
    }
    cout << endl;
  }
}
