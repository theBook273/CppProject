#include <bits/stdc++.h>

using namespace std;

long long main()
{
    string t, s;

    cin >> t >> s;

    if (t.size() != s.size())
    {
        return 0;
    }

    long long arr[26] = {0};

    for (long long i = 0; i < s.size(); i++)
    {
        arr[s[i] - 'a']++;
        arr[t[i] - 'a']--;
    }

    for (long long i = 0; i <= 25; i++)
    {
        if (arr[i] != 0)
        {
            return 0;
        }
    }

    return 1;
}
