#include <bits/stdc++.h>

using namespace std;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  vector<string> action;

  int mh, ma, mc;
  cin >> mh >> ma >> mc;

  int eh, ea;
  cin >> eh >> ea;

  while (eh > 0) {
    if (eh - ma <= 0) {
      eh -= ma;
      action.push_back("STRIKE");
    } else if (mh - ea <= 0) {
      action.push_back("HEAL");
      mh += mc;
    } else {
      eh -= ma;
      action.push_back("STRIKE");
    }
    mh -= ea;
  }
  cout << action.size() << "\n";
  for (auto i : action) {
    cout << i << "\n";
  }
}
