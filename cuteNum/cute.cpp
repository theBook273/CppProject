#include <bits/stdc++.h>

using namespace std;

class solution
{
private:
    long long n, k, bac = 0, tong = 0;

public:
    solution()
    {
        cin >> n >> k;
    }

    void solve()
    {
        while (tong < n)
        {
            tong += pow(k, bac);
            bac++;
        }

        bac--;

        cout << bac << " " << tong << endl;
    }
};

long long main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n;
    cin >> n;

    while (n--)
    {
        solution a;
        a.solve();
    }
}
