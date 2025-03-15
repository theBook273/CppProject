#include <bits/stdc++.h>

using namespace std;

void solve()
{
    string s;

    cin >> s;

    int n = s.size(), w, res = 0;

    cin >> w;

    s = 'X' + s;

    deque<int> vt;

    for (int l = 1, r = 1, cnt = 0; r <= n; r++)
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
            int maxx = 0;

            for (int i = 0; i < (int)vt.size(); i++)
            {
                maxx += min(vt[i] - i - l, r - (int)vt.size() + i + 1 - vt[i]);
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

int main()
{
    solve();
}