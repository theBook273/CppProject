#include <bits/stdc++.h>

using namespace std;

signed main() {
  int t;
  cin >> t;
  while (t--) {
    string temp;
    cin >> temp;
    cout << *min_element(temp.begin(), temp.end()) << "\n";
  }
}
