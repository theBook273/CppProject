#include <bits/stdc++.h>
#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<int>> threeSum(vector<int> &a) {
    sort(a.begin(), a.end());
    int n = a.size();

    vector<vector<int>> res;

    for (int i = 0; i < n; i++) {
      if (a[i] > 0)
        break;
      if (i > 1 && a[i] == a[i - 1])
        continue;

      int l = i + 1, r = n - 1;
      while (l < r) {
        int sum = a[l] + a[r] + a[i];
        if (sum > 0) {
          r--;
        } else if (sum < 0) {
          l++;
        } else {
          res.push_back({a[i], a[r], a[l]});
          l++;
          r--;
          while (l < r && a[l] == a[l - 1]) {
            l++;
          }
        }
      }
    }

    return res;
  }
};

signed main() {
  Solution res;
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &i : a) {
    cin >> i;
  }
  vector<vector<int>> show = res.threeSum(a);
  for (auto i : show) {
    for (auto j : i) {
      cout << j << "  ";
    }
    cout << "\n";
  }
}
