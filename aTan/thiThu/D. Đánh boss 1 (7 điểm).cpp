#include <bits/stdc++.h>
#include <cstdio>
#define int unsigned long long

using namespace std;

void mana(pair<int, int> &a) { a.first += a.second; }

signed main() {
  cin.tie()->sync_with_stdio(0);

  freopen("BOSS1.INP", "r", stdin);
  freopen("BOSS1.OUT", "w", stdout);

  int w, f, n;
  cin >> w >> f >> n;
  pair<int, int> water = {w, w}, fire = {f, f};
  vector<int> mon(n);
  for (int i = 0; i < n; i++) {
    cin >> mon[i];
  }

  sort(mon.rbegin(), mon.rend());
  int cnt = 1, lockOn = 0;

  while (lockOn < n) {
    while (water.first < mon[lockOn] && fire.first < mon[lockOn]) {
      cnt++;
      mana(water);
      mana(fire);
    }
    if (fire.first < water.first) {
      swap(water, fire);
    }
    while (lockOn < n && water.first >= mon[lockOn]) {
      water.first -= mon[lockOn];
      lockOn++;
    }
    while (lockOn < n && fire.first >= mon[lockOn]) {
      fire.first -= mon[lockOn];
      lockOn++;
    }
  }

  cout << cnt;
}
