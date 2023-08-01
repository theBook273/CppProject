#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, tong = 0;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        char temp;

        cin >> temp;

        if (temp == 'V' || temp == 'I' || temp == 'P')
        {
            tong++;
        }
    }

    cout << tong / 3;
}