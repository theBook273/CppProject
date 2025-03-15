#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;

    int temp = t;

    while (t--)
    {
        long long n, m, a[1000000], tong = 0;
        cin >> n >> m;

        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            tong += a[i];
        }

        cout << "Case #" << temp - t << ": " << tong - (tong / m * m) << endl;
    }
}