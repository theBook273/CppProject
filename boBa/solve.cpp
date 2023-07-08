#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a, b, z, y, m, n, tong = 0;

    cin >> a >> b >> z >> y >> m >> n;

    for (int i = a; i <= b; i++)
    {
        for (int j = z; j <= y; j++)
        {
            int temp = i * j;

            if (m <= temp && temp <= n)
            {
                tong++;
            }
        }
    }

    cout << tong;
}