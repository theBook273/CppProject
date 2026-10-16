#include <bits/stdc++.h>
#define int double
using namespace std;

signed main() {
  int hm, mm, ms;
  cin >> hm >> mm >> ms;

  int wh, wm, ws;
  cin >> wh >> wm >> ws;

  int total = hm * 60 * 60 + mm * 60 + ms;
  int watched = wh * 60 * 60 + wm * 60 + ws;
  cout << fixed << setprecision(0) << (watched * 100 / total);
}
