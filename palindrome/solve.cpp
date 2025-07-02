#include <bits/stdc++.h>

using namespace std;

long long main()
{
    string s;

    getline(cin, s);

    long long start = 0, last = s.size() - 1;

    while (start <= last)
    {

        if (!isalnum(s[start]))
        {
            start++;
            continue;
        }

        if (!isalnum(s[last]))
        {
            last--;
            continue;
        }

        s[start] = tolower(s[start]);
        s[last] = tolower(s[last]);

        if (s[start] != s[last])
        {
            return 0;
        }

        start++;
        last--;
    }

    return 1;
}
