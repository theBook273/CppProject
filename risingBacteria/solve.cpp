#include <bits/stdc++.h>

using namespace std;
long long x, res = 1e9, inbox = 1, putted = 0;

long long main()
{
    cin >> x;

    while (x != 0)
    {
        if (x & 1)
        {
            putted++;
        }
        x >>= 1;
    }

    cout << putted << endl;
}
