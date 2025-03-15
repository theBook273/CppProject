#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long n, tong = 0;

    cin >> n;

    string s;

    cin >> s;

    deque<char> q;

    unordered_map<char, int> se;

    for (int i = 0; i < n; i++)
    {
        q.push_back(s[i]);

        se[s[i]]++;
    }

    if (se.size() == 6)
    {
        tong++;
    }
    else
    {
        cout << 0;
        return 0;
    }

    while (se[q.front()] > 1 || se[q.back()] > 1)
    {
        if (se[q.front()] > 1)
        {
            se[q.front()]--;
            tong++;
            q.pop_front();
            for (auto i : q)
            {
                cout << i;
            }
            cout << "\n";
        }
        if (se[q.back()] > 1)
        {
            se[q.back()]--;
            tong++;
            q.pop_back();
            for (auto i : q)
            {
                cout << i;
            }
            cout << "\n";
        }
    }

    q.clear();
    se.clear();

    for (int i = 0; i < n; i++)
    {
        q.push_back(s[i]);

        se[s[i]]++;
    }

    while (se[q.back()] > 1)
    {
        se[q.back()]--;
        tong++;
        q.pop_back();
        for (auto i : q)
        {
            cout << i;
        }
        cout << "\n";
    }

    cout << tong;
}