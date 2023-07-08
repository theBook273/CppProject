#include <bits/stdc++.h>

using namespace std;

long long n, k, pos = -1, minG = 1e9;

string s, res[2];

int main()
{
    cin >> n >> k;

    cin >> s;

    if (k == 0)
    {
        cout << s << k;
        return 0;
    }

    for (int i = n - 1; i >= 0; i--)
    {
        if (s[i] - '0' <= k)
        {
            pos = i;
        }
    }

    if (pos == -1)
    {
        s += to_string(k);
        cout << s;
        return 0;
    }

    for (int i = 0; i < n; i++)
    {
        if (i == pos)
        {
            res[0] += to_string(k);
        }
        res[0] += s[i];
    }

    for (int i = n - 1; i >= 0; i--)
    {
        if (s[i] - '0' < k)
        {
            pos = i;
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (i == pos)
        {
            res[1] += to_string(k);
        }
        res[1] += s[i];
    }

    cout << max(res[0], res[1]);
}