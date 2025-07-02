#include <bits/stdc++.h>

using namespace std;

long long main()
{
    long long k;

    cin >> k;

    while (k--)
    {
        string s;
        for (long long i = 0; i < 8; i++)
        {
            for (long long j = 0; j < 8; j++)
            {
                char temp;
                cin >> temp;

                if (temp != '.')
                {
                    s += temp;
                }
            }
        }

        cout << s << endl;
    }
}
