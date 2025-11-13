#include <bits/stdc++.h>
using namespace std;
using int64 = long long;
const int64 MOD = 1000000007LL;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  freopen("test.inp", "r", stdin);
  freopen("testTrau.out", "w", stdout);
  string s;
  if (!(cin >> s))
    return 0;
  int n = (int)s.size();
  if (n % 2 == 1) { // độ dài lẻ => không thể tạo dãy đúng
    cout << 0 << '\n';
    return 0;
  }

  // dp[l][r] : số cách để s[l..r] là dãy ngoặc đúng
  vector<vector<int64>> dp(n, vector<int64>(n, 0));

  // helper: kiểm tra xem char a có thể là open loại t
  auto isOpen = [&](char a, char needOpen) {
    return (a == needOpen) || (a == '?');
  };
  auto isClose = [&](char a, char needClose) {
    return (a == needClose) || (a == '?');
  };

  // các loại ngoặc
  vector<pair<char, char>> types = {{'(', ')'}, {'[', ']'}, {'{', '}'}};

  // chiều dài đoạn (len)
  for (int len = 2; len <= n; ++len) {
    if (len % 2 == 1)
      continue; // chỉ xét len chẵn
    for (int l = 0; l + len - 1 < n; ++l) {
      int r = l + len - 1;
      int64 ways = 0;
      // ghép l với k; phần giữa l+1..k-1 và phần k+1..r
      for (int k = l + 1; k <= r; k += 2) {
        int64 leftInside = 1;
        if (k - 1 >= l + 1)
          leftInside = dp[l + 1][k - 1];
        int64 rightPart = 1;
        if (k + 1 <= r)
          rightPart = dp[k + 1][r];
        if (leftInside == 0 || rightPart == 0) {
          // nếu một trong 2 phần bằng 0 thì góp 0
          // nhưng vẫn cần kiểm tra loại ngoặc? thực tế nếu leftInside==0 hoặc
          // rightPart==0 thì nhân ra 0.
        }
        // thử cả 3 loại ngoặc
        int64 addTypes = 0;
        for (auto &tp : types) {
          if (isOpen(s[l], tp.first) && isClose(s[k], tp.second)) {
            addTypes = (addTypes + 1) % MOD;
          }
        }
        if (addTypes == 0)
          continue;
        ways = (ways + addTypes * ((leftInside * rightPart) % MOD)) % MOD;
      }
      dp[l][r] = ways;
    }
  }

  cout << dp[0][n - 1] % MOD << '\n';
  return 0;
}
