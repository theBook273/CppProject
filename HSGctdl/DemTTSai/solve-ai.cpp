#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<long long> lowers,
      uppers; // Sử dụng long long nếu p lớn, nhưng int cũng ok nếu p <= 1e9
  set<long long> all_vals;
  for (int i = 0; i < N; i++) {
    char type;
    long long p;
    cin >> type >> p;
    if (type == 'G') {
      lowers.push_back(p);
    } else {
      uppers.push_back(p);
    }
    all_vals.insert(p);
  }
  sort(lowers.begin(), lowers.end());
  sort(uppers.begin(), uppers.end());
  vector<long long> vals(all_vals.begin(), all_vals.end());

  long long max_keep = 0;
  for (auto m : vals) {
    // Số G với p <= m
    auto it_g = upper_bound(lowers.begin(), lowers.end(), m);
    long long num_g = it_g - lowers.begin();

    // Số L với p >= m
    auto it_l = lower_bound(uppers.begin(), uppers.end(), m);
    long long num_l = uppers.size() - (it_l - uppers.begin());

    max_keep = max(max_keep, num_g + num_l);
  }
  // Xử lý trường hợp không có G hoặc L (luôn nhất quán)
  // Đã bao gồm trong vòng lặp, vì khi m nhỏ: num_g=0, num_l=full nếu m <= min
  // uppers, v.v.

  cout << N - max_keep << endl;
  return 0;
}
