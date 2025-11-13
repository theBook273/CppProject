#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, q;
  cin >> n >> q;
  vector<long long> a(n + 2, 0); // thêm biên ảo để tránh out of bound
  for (int i = 1; i <= n; i++)
    cin >> a[i];

  // Tính giá trị ban đầu
  long long ans = 0;
  for (int i = 1; i < n; i++)
    ans += abs(a[i + 1] - a[i]);

  while (q--) {
    int l, r;
    long long x;
    cin >> l >> r >> x;

    // Trừ ảnh hưởng cũ ở biên
    if (l > 1)
      ans -= abs(a[l] - a[l - 1]);
    if (r < n)
      ans -= abs(a[r + 1] - a[r]);

    // Cập nhật
    a[l] += x;
    if (r < n)
      a[r + 1] += 0; // giữ nguyên phần sau r, chỉ cần a[r] tăng

    for (int i = l + 1; i <= r; i++)
      a[i] += x;

    // Cộng lại ảnh hưởng mới
    if (l > 1)
      ans += abs(a[l] - a[l - 1]);
    if (r < n)
      ans += abs(a[r + 1] - a[r]);

    cout << ans << '\n';
  }
  return 0;
}
