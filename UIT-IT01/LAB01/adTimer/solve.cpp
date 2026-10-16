#include <bits/stdc++.h>

using namespace std;

int euclid(int a, int b) {
  while (b) {
    a %= b;
    swap(a, b);
  }
  return a;
}

signed main() {
  int hm, mm, ms;
  cin >> hm >> mm >> ms;

  int wh, wm, ws;
  cin >> wh >> wm >> ws;

  int total = hm * 60 * 60 + mm * 60 + ms;
  int watched = wh * 60 * 60 + wm * 60 + ws;
  int eu = euclid(total, watched);
  cout << watched / eu << " " << total / eu;
}
