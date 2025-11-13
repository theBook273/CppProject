#include <bits/stdc++.h>
#define int long long

using namespace std;

vector<int> a, zeroCntL, zeroCntR;
vector<int> dem(2);
int n;

class linkedList {
private:
  struct node {
    int val;
    bool mark;
    node *next;
    node() {
      val = 0;
      next = nullptr;
      mark = 0;
    }
    node(int val) {
      this->val = val;
      next = nullptr;
      mark = 0;
    }
  };

public:
  node *sigList = nullptr;

  void push(int x) {
    node *temp = new node(x);
    if (sigList == nullptr) {
      sigList = temp;
      return;
    }
    node *p = sigList;
    while (p->next != nullptr) {
      p = p->next;
    }
    p->next = temp;
  }

  void markX(int x) {
    node *p = sigList;
    int id = 0;
    while (p != nullptr && id < x) {
      id++;
      p = p->next;
    }
    p->mark = 1;
  }

  void remove() {
    while (sigList && sigList->val == 1 && sigList->mark == 0) {
      node *temp = sigList;
      sigList = sigList->next;
      delete temp;
    }
    if (!sigList)
      return;

    node *p1 = sigList;
    node *p2 = sigList->next;

    while (p2 != nullptr) {
      if (p2->val == 1 && p2->mark == 0) {
        p1->next = p2->next;
        delete p2;
        p2 = p1->next;
      } else {
        p1 = p2;
        p2 = p2->next;
      }
    }
  }

  vector<int> show() {
    node *p = sigList;
    vector<int> res;
    while (p != nullptr) {
      res.push_back(p->val);
      p = p->next;
    }
    return res;
  }
};

signed main() {
  cin.tie()->sync_with_stdio(0);
  cin >> n;
  a.resize(n), zeroCntL.resize(n), zeroCntR.resize(n);
  char temp;
  for (int i = 0; i < n; i++) {
    cin >> temp;
    a[i] = temp - '0';
    dem[a[i]]++;
  }

  if (dem[0] == 0) {
    cout << n;
    return 0;
  }

  for (int cnt = 0, i = 0; i < n; i++) {
    if (a[i] == 1) {
      zeroCntL[i] = cnt;
      cnt = 0;
      continue;
    }
    cnt++;
  }

  for (int cnt = 0, i = n - 1; i >= 0; i--) {
    if (a[i] == 1) {
      zeroCntR[i] = cnt;
      cnt = 0;
      continue;
    }
    cnt++;
  }

  unordered_set<int> se;
  for (int i = 0; i < n; i++) {
    if (a[i]) {
      se.insert(zeroCntL[i]);
      se.insert(zeroCntR[i]);
    }
  }

  if (se.size() == 1) {
    cout << n;
    return 0;
  }

  if (dem[1] == 1 && (a[0] == 1 || a[n - 1] == 1)) {
    cout << 1;
    return 0;
  }

  if (dem[0] < dem[1]) {
    cout << n - dem[0];
    return 0;
  }

  if (n % 2 != 0) {
    pair<int, int> tracking = {n / 2, n / 2};
    int cen = tracking.first;

    if (a[cen] != 1) {
      for (; tracking.second < n && a[tracking.second] != 1;
           tracking.second++) {
      }

      for (; tracking.first >= 0 && a[tracking.first] != 1; tracking.first--) {
      }
      // cout << tracking.first << " " << tracking.second;

      int trackT = 0;
      for (int i = tracking.first; i >= 0; i--) {
        trackT += (a[i] == 0);
      }

      int trackP = 0;
      for (int i = tracking.second; i < n; i++) {
        trackP += (a[i] == 0);
      }
      cen = tracking.first;
      if (trackT < trackP) {
        cen = tracking.second;
      }
    }

    linkedList ls;
    for (auto i : a) {
      ls.push(i);
    }
    ls.markX(cen);
    ls.remove();
    a = ls.show();
    n = a.size();

    for (int i = 0; i < n; i++) {
      if (a[i] == 1) {
        cout << min(i, n - i - 1) * 2 + 1;
        return 0;
      }
    }

  } else if (n % 2 == 0) {
    pair<int, int> tracking = {n / 2 - 1, n / 2};

    for (; tracking.second < n && a[tracking.second] != 1; tracking.second++) {
    }

    for (; tracking.first >= 0 && a[tracking.first] != 1; tracking.first--) {
    }

    int trackT = 0;
    for (int i = tracking.first; i >= 0; i--) {
      trackT += (a[i] == 0);
    }

    int trackP = 0;
    for (int i = tracking.second; i < n; i++) {
      trackP += (a[i] == 0);
    }

    int cen = tracking.first;
    if (trackT < trackP || a[tracking.first] == 0) {
      cen = tracking.second;
    }

    linkedList ls;
    for (auto i : a) {
      ls.push(i);
    }
    ls.markX(cen);
    ls.remove();
    a = ls.show();
    n = a.size();

    for (int i = 0; i < n; i++) {
      if (a[i] == 1) {
        cout << min(i, n - i - 1) * 2 + 1;
        return 0;
      }
    }
  }
}
