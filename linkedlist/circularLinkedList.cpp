#include <bits/stdc++.h>

using namespace std;

class circularLinkedList {
private:
  struct node {
    long long data;
    node *next;

    node(long long val) {
      data = val;
      next = nullptr;
    }
  };

public:
  node *head = nullptr;

  void push_back(long long val) {
    node *temp = new node(val);
    if (head == nullptr) {
      head = temp;
    } else {
      node *p = head;
      while (p->next != nullptr) {
        p = p->next;
      }
      p->next = temp;
    }
  }

  void makeCircle() {
    node *p = head;
    while (p->next != nullptr) {
      p = p->next;
    }
    p->next = head;
  }

  void show() {
    node *p = head;
    while (p != nullptr) {
      cout << p->data << " ";
      p = p->next;
    }
  }

  void showFrom(long long x) {
    node *p1, *p2;
    p1 = p2 = head;
    for (long long i = 0; i < x; i++) {
      p2 = p2->next;
      p1 = p1->next;
    }

    cout << p2->data << " ";

    p1 = p1->next;

    while (p1 != p2) {
      cout << p1->data << " ";
      p1 = p1->next;
    }
  }
};

signed main() {
  circularLinkedList a;

  long long n;
  cin >> n;

  for (long long i = 0; i < n; i++) {
    long long temp = 0;
    cin >> temp;
    a.push_back(temp);
  }

  a.makeCircle();

  long long x;
  cin >> x;

  a.showFrom(x);
}
