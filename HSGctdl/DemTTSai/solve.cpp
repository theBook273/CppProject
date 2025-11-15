#include <algorithm>
#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<int> lower, uppers;
  set<int> allVals;

  for (int i = 0; i < n; i++) {
    char type;
    int p;
    cin >> type >> p;
    if (type == 'G') {
      lower.push_back(p);
    } else {
      uppers.push_back(p);
    }
    allVals.insert(p);
  }

  sort(lower.begin(), lower.end());
  sort(uppers.begin(), uppers.end());
  vector<int> vals(allVals.begin(), allVals.end());

  int max_keep = 0;
  for (auto m : vals) {
    int num_g = upper_bound(lower.begin(), lower.end(), m) - lower.begin();

    int num_l = uppers.size() -
                (lower_bound(uppers.begin(), uppers.end(), m) - uppers.begin());

    max_keep = max(max_keep, num_g + num_l);
  }

  cout << n - max_keep << "\n";
}
