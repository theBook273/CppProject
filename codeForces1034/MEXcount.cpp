#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>

using namespace std;

int countMex(vector<int> a, unordered_map<int, int> mp, int deMex, int k) {
  int l = 0, r = 0, n = a.size(), temp = deMex;
  unordered_set<int> cnt;
  for (; r < n; ++r) {
    mp[a[r]]--;
    cout << a[l] << " " << a[r] << "\n";
    if (mp[a[r]] == 0)
      temp = min(temp, a[r]);
    if (r - l + 1 == k) {
      cnt.insert(temp);
      temp = deMex;
      mp[a[l]]++;
      l++;
    }
  }
  return cnt.size();
}

signed main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n);
    unordered_map<int, int> mp;
    for (auto &i : a) {
      cin >> i;
      mp[i]++;
    }
    sort(a.begin(), a.end());
    int deMex = 0;
    for (auto i : a) {
      if (i == deMex)
        deMex++;
    }

    cout << countMex(a, mp, deMex, 2);
  }
}
