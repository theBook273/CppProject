#include "machine.h"
#include <bits/stdc++.h>

using namespace std;

signed main() {
  cin.tie()->sync_with_stdio(0);
  Captain cap;
  Soldier sol(1);
  string s = "11:30:00";
  string converted = cap.encode(s);
  for (int flip = 1; flip <= converted.size(); flip++) {
    string temp = converted;
    temp[flip] = (temp[flip] == '0' ? '1' : '0');
    if (sol.decode(temp) != s) {
      cout << flip << "\n";
    }
  }
}
