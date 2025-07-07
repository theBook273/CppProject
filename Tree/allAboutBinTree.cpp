#include <bits/stdc++.h>

using namespace std;

class binTree {
private:
  struct node {
    int data;
    node *left;
    node *right;
    node(int val) {
      data = val;
      right = nullptr;
      left = nullptr;
    }
  };

public:
  node *root = nullptr;

  bool isANode(node *now) {
    return (now->left != nullptr || now->right != nullptr);
  }

  bool isAVL(node *now) {
    if (now == nullptr)
      return true;
    if (abs(levelOfTree(now->left) - levelOfTree(now->right)) > 1)
      return false;
    return (isAVL(now->left) && isAVL(now->right));
  }

  void push(node *&now, int val) {
    if (now == nullptr) {
      node *toAdd = new node(val);
      now = toAdd;
    } else {
      if (val < now->data)
        push(now->left, val);
      else
        push(now->right, val);
    }
  }

  int letsCount(node *now) {
    if (!isANode(now))
      return 1;
    int l = 0, r = 0;
    if (now->left != nullptr)
      l = letsCount(now->left);
    if (now->right != nullptr)
      r = letsCount(now->right);
    return r + l;
  }

  int levelOfTree(node *now) {
    if (now == nullptr)
      return -1;
    return (1 + max(levelOfTree(now->left), levelOfTree(now->right)));
  }

  node *turnRight(node *now) {
    node *a = now->left;
    node *b = a->right;
    now->left = b;
    a->right = now;
    return a;
  }

  node *turnLeft(node *now) {
    node *a = now->right;
    node *b = a->left;
    now->right = b;
    a->left = now;
    return a;
  }

  node *makeAVL(node *now) {
    if (!isAVL(now)) {
      if (levelOfTree(now->left) > levelOfTree(now->right)) {
        node *p = now->left;
        if (levelOfTree(p->left) >= levelOfTree(p->right)) {
          now = turnRight(now);
        } else {
          now->left = turnLeft(now->left);
          now = turnRight(now);
        }
      } else {
        node *p = now->right;
        if (levelOfTree(p->right) >= levelOfTree(p->left)) {
          now = turnLeft(now);
        } else {
          now->right = turnRight(now->right);
          now = turnLeft(now);
        }
      }
    }
    if (now->left != nullptr) {
      now->left = makeAVL(now->left);
    }
    if (now->right != nullptr) {
      now->right = makeAVL(now->right);
    }
    return now;
  }

  int countIn(node *now, int val) {
    if (now == nullptr)
      return 0;
    if (now->data == val)
      return 1 + countIn(now->left, val) + countIn(now->right, val);
    else if (now->data > val)
      return countIn(now->left, val);
    return countIn(now->right, val);
  }

  void remove(node *&now) {
    if (now == nullptr)
      return;
    if (!isANode(now))
      now = nullptr;
    else {
      remove(now->left);
      remove(now->right);
      now = nullptr;
    }
  }

  void removeAt(node *&now, int val) {
    if (now == nullptr)
      return;
    if (now->data == val) {
      remove(now);
    } else {
      if (val < now->data)
        removeAt(now->left, val);
      else
        removeAt(now->right, val);
    }
  }

  void show(node *now) {
    if (now != nullptr) {
      show(now->left);
      cout << now->data << " ";
      show(now->right);
    }
  }
};

signed main() {
  binTree a;
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    int temp;
    cin >> temp;
    a.push(a.root, temp);
  }
  int x;
  cin >> x;
  a.removeAt(a.root, x);
  if (a.root == nullptr)
    cout << "NULL";
  else
    a.show(a.root);
}
