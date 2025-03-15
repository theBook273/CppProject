#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int main()
{
    map<long long, long long> a;
    set<long long> se;

    long long n, q;

    cin >> n >> q;

    while (q--)
    {
        long long x, y, tich = 1, tong = 1;

        map<long long, long long> mp;

        cin >> x >> y;

        a[x] = y;
        se.insert(x);

        for (long long i : se)
        {
            tich *= a[i];
        }

        for (long long i = 2; i <= tich; i++)
        {
            while (tich % i == 0)
            {
                mp[i]++;
                tich /= i;
            }
        }

        for (auto i : mp)
        {
            tong *= (i.second + 1);
            tong %= int(1e9 + 7);
        }

        cout << tong << "\n";
    }
}