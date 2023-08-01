#include <bits/stdc++.h>

using namespace std;

int main()
{
    // freopen("CLOCK.INP", "r", stdin);
    // freopen("CLOCK.OUT", "w", stdout);

    int m;
    string n;

    cin >> n >> m;

    while (n.size() > 2)
    {
        stack<int> minus;
        int remem = 0;
        for (int i = n.size() - 1; i >= 0; i++)
        {
            if (i == n.size() - 1)
            {
                minus.push(n[i] - '0');
            }

            else if (i == n.size() - 2)
            {
                if (n[i] - '0' - 6 >= 0)
                {
                    minus.push(n[i] - '0' - 6);
                }

                else
                {
                    minus.push(n[i] - '0' + 10 - 6);
                    remem = 1;
                }
            }

            else
            {
                if (n[i] - '0' - remem >= 0)
                {
                    minus.push(n[i] - '0' - remem);
                    remem = 0;
                }
                else
                {
                    minus.push(n[i] - '0' + 10 - remem);
                    remem = 1;
                }
            }
        }
    }

    while (res >= 60)
    {
        res -= 60;
    }

    cout << res << endl;
}