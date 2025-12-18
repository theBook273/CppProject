#include <bits/stdc++.h>
#include <iomanip>
#define int long long
#define double long double

using namespace std;

struct block {
  double sum;
  int cnt;
};

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<double> a(n, 0);
  for (auto &i : a) {
    cin >> i;
  }

  vector<block> st;

  for (int i = 0; i < n; i++) {
    st.push_back({a[i], 1});

    while (st.size() >= 2) {
      int m = st.size();
      double avg1 = st[m - 1].sum / st[m - 1].cnt;
      double avg2 = st[m - 2].sum / st[m - 2].cnt;

      if (avg2 > avg1) {
        st[m - 2].sum += st[m - 1].sum;
        st[m - 2].cnt += st[m - 1].cnt;
        st.pop_back();
      } else {
        break;
      }
    }
  }

  double res = 0;
  int id = 0;
  for (auto &b : st) {
    double avg = b.sum / b.cnt;
    for (int i = 0; i < b.cnt; i++) {
      double temp = a[id++] - avg;
      res += (temp * temp);
    }
  }

  cout << fixed << setprecision(9) << sqrt(res);
}
