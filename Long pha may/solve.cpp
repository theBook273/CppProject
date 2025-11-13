#include <bits/stdc++.h>
using namespace std;
bool visited[100001];
signed main() {
  long long t;
  cin >> t;
  while (t--) {
    long long n, k;
    cin >> n >> k;
    vector<pair<long long, long long>> p;
    long long gioihan = k;
    while (k--) {
      long long nhan, gia;
      cin >> nhan >> gia;
      p.push_back({nhan, gia});
      // for (auto x : p) {
      //     cout << x.first << " " << x.second << "\n";
      // }
    }
    sort(p.begin(), p.end());
    long long sum = 0;
    for (long long i = 0; i < p.size(); i++) {
      // cout << p[i].first << " " << p[i].second << " \n";
      long long kecu = p[i - 1].first;
      if (p[i].first != kecu)
        n--;
      sum += p[i].second;
      if (n == 0)
        break;
    }
    cout << sum << " \n";
  }
}
