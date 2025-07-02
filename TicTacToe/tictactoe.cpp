#include <bits/stdc++.h>

using namespace std;

class solution
{
private:
    char a[3][3];

public:
    solution()
    {
        for (long long i = 0; i < 3; i++)
        {
            for (long long j = 0; j < 3; j++)
            {
                cin >> a[i][j];
            }
        }
    }

    char horizontal()
    {
        for (long long i = 0; i < 3; i++)
        {
            if (a[i][0] == a[i][1] && a[i][1] == a[i][2] && a[i][0] != '.')
            {
                return a[i][0];
            }
        }
        return '0';
    }

    char vertical()
    {
        for (long long i = 0; i < 3; i++)
        {
            if (a[0][i] == a[1][i] && a[1][i] == a[2][i] && a[0][i] != '.')
            {
                return a[0][i];
            }
        }
        return '0';
    }

    char diagonal()
    {
        if (a[0][0] == a[1][1] && a[1][1] == a[2][2] && a[0][0] != '.')
        {
            return a[0][0];
        }
        else if (a[0][2] == a[1][1] && a[1][1] == a[2][0] && a[0][2] != '.')
        {
            return a[0][2];
        }
        return '0';
    }

    void check()
    {
        if (horizontal() != '0')
        {
            cout << horizontal() << endl;
        }
        else if (vertical() != '0')
        {
            cout << vertical() << endl;
        }
        else if (diagonal() != '0')
        {
            cout << diagonal() << endl;
        }
        else
        {
            cout << "DRAW" << endl;
        }
    }
};

long long main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long t;
    cin >> t;
    while (t--)
    {
        solution a;
        a.check();
    }
}
