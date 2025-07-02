#include <bits/stdc++.h>

using namespace std;

struct node {
  int data;
  node *prev;
  node *next;
};

struct doubList {
  node *head;
  node *tail;
};

doubList *createDoublist(int val) {
  doubList *temp = new doubList;
  temp->head = new node;
  temp->head->data = val;
  temp->head->prev = nullptr;
  temp->head->next = nullptr;
  temp->tail = temp->head;
  return temp;
}

doubList *push_front(doubList *lis, int val) {
  node *temp = new node;
  temp->data = val;
  temp->prev = nullptr;
  temp->next = lis->head;
  lis->head->prev = temp;
  lis->head = temp;
  return lis;
}

doubList *pop_front(doubList *lis) {
  node *p = lis->head->next;
  node *temp = lis->head;
  p->prev = nullptr;
  lis->head = p;
  delete (temp);
  return lis;
}

doubList *push_back(doubList *lis, int val) {
  node *temp = new node;
  temp->data = val;
  temp->next = nullptr;
  temp->prev = lis->tail;
  lis->tail->next = temp;
  lis->tail = temp;
  return lis;
}

doubList *pop_back(doubList *lis) {
  node *p = lis->tail->prev;
  node *temp = lis->tail;
  p->next = nullptr;
  lis->tail = p;
  delete (temp);
  return lis;
}

doubList *insertAt(doubList *lis, int pos, int val) {
  node *p1 = lis->head;
  int cnt = 0;

  while (p1 != nullptr && cnt <= pos) {
    if (cnt == pos) {
      node *p2 = p1;
      p1 = p1->prev;
      node *temp = new node;
      temp->data = val;
      temp->next = p2;
      p2->prev = temp;
      temp->prev = p1;
      p1->next = temp;
      return lis;
    }
    p1 = p1->next;
    cnt++;
  }
  return lis;
}

doubList *removeAt(doubList *lis, int pos) {
  node *p = lis->head;

  for (int i = 0; i < pos; i++) {
    p = p->next;
  }

  node *p1 = p->prev;
  node *p2 = p->next;

  p1->next = p2;
  p2->prev = p1;

  delete (p);

  return lis;
}

void printLis(doubList *lis) {
  node *p = lis->head;
  while (p != nullptr) {
    cout << p->data << " ";
    p = p->next;
  }
}

signed main() {
  int n;
  cin >> n;

  int temp;
  cin >> temp;
  doubList *lis = createDoublist(temp);

  for (int i = 1; i < n; ++i) {
    cin >> temp;
    lis = push_back(lis, temp);
  }

  int k;
  cin >> k;

  if (k == 0)
    lis = pop_front(lis);
  else if (k == n - 1)
    lis = pop_back(lis);
  else
    lis = removeAt(lis, k);

  printLis(lis);

  return 0;
}
