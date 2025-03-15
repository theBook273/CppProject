#include <bits/stdc++.h>
#include "classStack.h"

using namespace std;

int main()
{
    MinStack minStack;
    minStack.push(-2);
    minStack.push(0);
    minStack.push(-3);
    cout << minStack.getMin(); // return -3
    minStack.pop();
    minStack.top();            // return 0
    cout << minStack.getMin(); // return -2
}