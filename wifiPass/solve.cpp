#include <bits/stdc++.h>

using namespace std;

long long main()
{
    freopen("PASS.INP", "r", stdin);
    freopen("PASS.OUT", "w", stdout);

    string a;

    vector<long long> alphabet(27, 0);
    queue<long long> loc;

    cin >> a;

    for (long long i = 0; i < 26; i++)
    {
        cin >> alphabet[i];
        if (alphabet[i] != 0)
        {
            loc.push(i);
        }
    }

    for (long long i = 0; i < a.length(); i++)
    {
        if (a[i] == '*')
        {
            if (alphabet[loc.front()] != 0)
            {
                a[i] = loc.front() + 97;
                alphabet[loc.front()]--;
            }

            if (alphabet[loc.front()] == 0)
            {
                loc.pop();
            }
        }
    }

    cout << a << endl;
}
