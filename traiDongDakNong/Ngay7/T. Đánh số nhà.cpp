#include <bits/stdc++.h>
#define int unsigned long long

using namespace std;

vector<int> mp(10, 0);

void process(int n) {
  while (n) {
    mp[n % 10]++;
    n /= 10;
  }
}

signed main() {
  cin.tie()->sync_with_stdio(0);
  int n, k;
  cin >> n >> k;

  for (int i = 0; i < k; i++) {
    process(n + 2 * i);
  }

  for (auto i : mp) {
    cout << i << " ";
  }
}
