#include <bits/stdc++.h>

using namespace std;

struct Node {
  int data;
  Node *next;
};

Node *createNode(int val) {
  Node *newOne = new Node();
  newOne->data = val;
  newOne->next = nullptr;
  return newOne;
}

void insertBack(Node *&head, int val) {
  Node *newOne = createNode(val);

  if (head == nullptr) {
    head = newOne;
    return;
  }

  Node *temp = head;

  while (temp->next != nullptr) {
    temp = temp->next;
  }
  temp->next = newOne;
}

Node *insertPos(Node *head, int n, int pos, int val) {
  if (pos == n) {
    insertBack(head, val);
    return head;
  }

  if (pos == 0) {
    Node *newHead = createNode(val);
    newHead->next = head;
    return newHead;
  }

  Node *p1 = head, *p2 = head;
  int cnt = 1;

  p2 = p2->next;

  while (p2 != nullptr && cnt <= pos) {
    if (cnt == pos) {
      Node *temp = createNode(val);
      p1->next = temp;
      temp->next = p2;
      break;
    }
    cnt++;
    p2 = p2->next;
    p1 = p1->next;
  }

  return head;
}

Node *removeNode(Node *head, int pos) {
  Node *dummy = createNode(0);
  dummy->next = head;

  Node *p1, *p2;
  p1 = p2 = head;
  p2 = p2->next;
  int cnt = 1;

  if (pos == 0) {
    return p2;
  }

  while (p2 != nullptr && cnt <= pos) {
    if (cnt == pos) {
      p1->next = p2->next;
      break;
    }
    cnt++;
    p1 = p1->next;
    p2 = p2->next;
  }

  return dummy->next;
}

Node *replaceAwithB(Node *head, int a, int b) {
  Node *dummy = createNode(0);
  dummy->next = head;

  while (head != nullptr) {
    if (head->data == a)
      head->data = b;
    head = head->next;
  }
  return dummy->next;
}

Node *removeBigger(Node *head, int a) {
  Node *dummy = createNode(0);
  dummy->next = head;

  Node *p1, *p2;
  p1 = p2 = head;
  p2 = p2->next;

  while (p1->data > a) {
    dummy->next = p1->next;
    p1 = p1->next;
    p2 = p2->next;
  }

  while (p2 != nullptr) {
    if (p2->data > a) {
      p1->next = p2->next;
      p2 = p2->next;
    } else {
      p1 = p1->next;
      p2 = p2->next;
    }
  }

  return dummy->next;
}

void printLis(Node *head) {
  while (head != nullptr) {
    cout << head->data << " ";
    head = head->next;
  }
}

int getDataAt(Node *head, int pos) {
  int cnt = 0;
  while (head != nullptr && cnt <= pos) {
    if (cnt == pos) {
      return head->data;
    }
    cnt++;
    head = head->next;
  }
  return head->data;
}

signed main() {
  Node *lis = nullptr;

  int n;
  cin >> n;

  for (int i = 0; i < n; ++i) {
    int temp;
    cin >> temp;

    insertBack(lis, temp);
  }

  int a;
  cin >> a;

  lis = removeBigger(lis, getDataAt(lis, a));

  printLis(lis);

  return 0;
}
