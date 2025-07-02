#include <bits/stdc++.h>

using namespace std;

long long n, a;

long long main()
{
    string s;

    cin >> s;

    cin >> n;

    while (n--)
    {
        cin >> a;

        string temp = s.substr(0, a - 1);

        string needRev = s.substr(a - 1, s.size() - a + 1 - a + 1);

        reverse(needRev.begin(), needRev.end());

        s = temp + needRev + s.substr(s.size() - a + 1);
    }

    cout << s;
}
