#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;

    while (n--)
    {
        int a[3];

        for (int i = 0; i < 3; i++)
        {
            cin >> a[i];
        }

        sort(a, a + 3);
        reverse(a, a + 3);

        if (a[0] + a[1] >= 10)
        {
            cout << "YES" << endl;
            continue;
        }
        cout << "NO" << endl;
    }
}