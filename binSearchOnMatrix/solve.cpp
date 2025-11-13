#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  bool searchMatrix(vector<vector<int>> &matrix, int target) {
    int row = -1;
    for (int i = 0; i < matrix.size(); i++) {
      if (matrix[i][0] <= target && target <= matrix[i][matrix[i].size() - 1]) {
        row = i;
        break;
      }
    }

    if (row == -1) {
      return false;
    }

    int l = 0, r = matrix[row].size() - 1, m;
    while (l <= r) {
      m = (l + r) / 2;
      if (matrix[row][m] <= target) {
        if (matrix[row][m] == target) {
          return true;
        }
        l = m + 1;
      } else {
        r = m - 1;
      }
    }

    return false;
  }
};
