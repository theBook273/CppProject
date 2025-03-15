#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;

    cin >> t;

    while (t--)
    {
        int n;
        pair<int, int> maxOfThem = {0, 0};

        cin >> n;

        for (int i = 1; i <= n; i++)
        {
            int w, q;

            cin >> w >> q;

            if (w <= 10 && q > maxOfThem.second)
            {
                maxOfThem = {i, q};
            }
        }

        cout << maxOfThem.first << "\n";
    }
}