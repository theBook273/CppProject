#include <bits/stdc++.h>
#define int long long

using namespace std;

class linkedList {
private:
  struct node {
    int val;
    node *next;
    node() {
      val = 0;
      next = nullptr;
    }
    node(int a) {
      val = a;
      next = nullptr;
    }
  };

public:
  int now = 1, handling = 1;
  node *head = new node(0);

  void push(int p, int k) {
    node *point = head;
    while (point->val != p) {
      point = point->next;
    }
    while (k--) {
      if (point->next == nullptr) {
        node *ins = new node(now);
        point->next = ins;
        handling++;
      } else {
        node *ins = new node(now);
        ins->next = point->next;
        point->next = ins;
        handling++;
      }
      now++;
      point = point->next;
    }
  }

  void remove(int p, int k) {
    node *point = head;
    while (point->val != p) {
      point = point->next;
    }
    while (k--) {
      if (point->next == nullptr) {
        break;
      } else {
        node *rm = point->next;
        point->next = rm->next;
        delete rm;
        handling--;
      }
    }
  }

  int getMid() {
    int tar = ceil(handling / 2.0);
    int dem = 1;
    node *p = head;
    while (p != nullptr && dem < tar) {
      p = p->next;
      dem++;
    }
    return p->val;
  }

  // void print() {
  //   node *p = head;
  //   while (p != nullptr) {
  //     cout << p->val << " ";
  //     p = p->next;
  //   }
  // }
};

int q, p, k, now = 1;

signed main() {
  cin.tie()->sync_with_stdio(0);

  freopen("INSDEL.INP", "r", stdin);
  freopen("INSDEL.OUT", "w", stdout);

  linkedList a;
  cin >> q;
  while (q--) {
    cin >> p >> k;
    if (k > 0) {
      a.push(p, k);
    } else {
      a.remove(p, abs(k));
    }
    cout << a.getMid() << "\n";
    // a.print();
    // cout << "\n";
    // cout << a.handling;
    // cout << "\n\n";
  }
}
