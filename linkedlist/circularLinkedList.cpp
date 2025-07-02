#include <bits/stdc++.h>

using namespace std;

class circularLinkedList {
private:
  struct node {
    int data;
    node *next;

    node(int val) {
      data = val;
      next = nullptr;
    }
  };

public:
  node *head = nullptr;

  void push_back(int val) {
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

  void showFrom(int x) {
    node *p1, *p2;
    p1 = p2 = head;
    for (int i = 0; i < x; i++) {
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

  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    int temp = 0;
    cin >> temp;
    a.push_back(temp);
  }

  a.makeCircle();

  int x;
  cin >> x;

  a.showFrom(x);
}
