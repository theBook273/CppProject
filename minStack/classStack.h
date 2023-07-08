#include <bits/stdc++.h>

using namespace std;

class MinStack
{
private:
    stack<int> s;
    unordered_map<int, int> mp;
    priority_queue<int, vector<int>, greater<int>> priorityQueue;

public:
    MinStack()
    {
    }

    void push(int val)
    {
        s.push(val);
        priorityQueue.push(val);
        mp[val]++;
    }

    void pop()
    {
        mp[s.top()]--;
        if (mp[s.top()] == 0)
        {
            mp.erase(s.top());
        }
        s.pop();
    }

    int top()
    {
        return s.top();
    }

    int getMin()
    {
        while (mp.count(priorityQueue.top()) == 0)
        {
            priorityQueue.pop();
        }
        return priorityQueue.top();
    }
};