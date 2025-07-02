#include <bits/stdc++.h>

using namespace std;

void solve()
{
    string s;

    cin >> s;

    long long n = s.size(), w, res = 0;

    cin >> w;

    s = 'X' + s;

    deque<long long> vt;

    for (long long l = 1, r = 1, cnt = 0; r <= n; r++)
    {
        if (s[r] == '.')
        {
            cnt++;
        }
        else
        {
            vt.push_back(r);
        }
        if (cnt == w)
        {
            long long maxx = 0;

            for (long long i = 0; i < (long long)vt.size(); i++)
            {
                maxx += min(vt[i] - i - l, r - (long long)vt.size() + i + 1 - vt[i]);
            }

            res = min(res, maxx);
            while (s[l] == 'X')
            {
                l++, vt.pop_front();
            }

            l++;

            while (s[l] == 'X')
            {
                l++, vt.pop_front();
            }

            cnt--;
        }
    }
    cout << res << endl;
}

long long main()
{
    solve();
}
