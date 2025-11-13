#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

const char ngoac[] = {'(', ')'};

unordered_map<int, vector<int>> mp;
unordered_map<char, int> demNgoac;
vector<int> a;
vector<char> s;
int n;

bool check(vector<char> s) {
  stack<char> st;
  for (auto i : s) {
    if (i == '(' || st.empty()) {
      st.push(i);
    } else if (i == ')') {
      if (st.top() == '(') {
        st.pop();
      } else {
        return 0;
      }
    }
  }
  return st.empty();
}

void gen(int dem) {
  if (dem == n) {
    if (check(s)) {
      for (auto i : s) {
        cout << i;
      }
      cout << "\n";
    }
    return;
  }
  for (auto i : ngoac) {
    if (s[dem] == 0) {
      for (auto x : mp[a[dem]]) {
        s[x] = i;
      }

      gen(dem + 1);

      for (auto x : mp[a[dem]]) {
        s[x] = 0;
      }
    } else {
      gen(dem + 1);
    }
  }
}

signed main() {
  cin.tie()->sync_with_stdio(0);
  int x;
  while (cin >> x) {
    a.push_back(x);
  }
  n = a.size();
  for (int i = 0; i < n; i++) {
    mp[a[i]].push_back(i);
  }

  s.resize(n, 0);
  gen(0);
}
