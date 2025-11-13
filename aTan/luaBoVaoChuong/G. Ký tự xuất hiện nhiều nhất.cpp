#include <bits/stdc++.h>
#include <pthread.h>

using namespace std;

signed main() {
  cin.tie()->sync_with_stdio(0);

  vector<int> dem(26, 0);
  vector<char> chu = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i',
                      'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r',
                      's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

  string s;
  cin >> s;

  for (auto i : s) {
    dem[i - 'a']++;
  }

  char res = 'a';
  int maxF = 0;

  for (int i = 0; i < 26; i++) {
    if (dem[i] > maxF) {
      maxF = dem[i];
      res = chu[i];
    }
  }

  cout << res << " " << maxF;
}
