#include <bits/stdc++.h>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode *reverseList(ListNode *head) {
    ListNode *p1 = head;
    if (p1->next != nullptr) {
      ListNode *p2 = head->next;
      p1->next = nullptr;
      while (p2->next != nullptr) {
        ListNode *temp = p2->next;
        p2->next = p1;
        p1 = p2;
        if (temp != nullptr)
          p2 = temp;
      }
      p2->next = p1;
      return p2;
    } else
      return head;
  }
};
