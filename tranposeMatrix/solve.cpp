#include "head.h"
#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> test = {{1, 2, 3}, {4, 5, 6}};

signed main() {
  Solution res;
  vector<vector<int>> solve = res.transpose(test);
  for (vector<int> i : solve) {
    for (int j : i) {
      cout << j << " ";
    }
    cout << "\n";
  }
}
