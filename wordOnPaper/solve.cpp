#include <bits/stdc++.h>

using namespace std;

int main()
{
    int k;

    cin >> k;

    while (k--)
    {
        string s;
        for (int i = 0; i < 8; i++)
        {
            for (int j = 0; j < 8; j++)
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