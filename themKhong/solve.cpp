#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, k;

    deque<int> q;

    cin >> n >> k;

    for (int i = 0; i < n; i++)
    {
        int temp;

        cin >> temp;

        q.push_back(temp);
    }

    while (k--)
    {
        q.pop_front();
        q.push_back(0);
    }

    for (int i : q)
    {
        cout << i << " ";
    }
}