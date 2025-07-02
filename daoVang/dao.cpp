#include <bits/stdc++.h>

using namespace std;

long long n, k, a[1000000], cat = 0;

long long bincut(long long a[], long long l, long long r)
{
    long long mid = (a[l] + a[r]) / 2;

    cat++;

    if (cat == k)
    {
        return min(mid - a[l], a[r] - mid);
    }

    long long mid1, mid2;

    for (long long i = 0; i < n; i++)
    {
        if (a[i] <= mid)
        {
            mid1 = i;
        }
        if (a[i] >= mid)
        {
            mid2 = i;
        }
    }

    if (cat < k)
    {
        bincut(a, l, mid1);
        bincut(a, mid2, r);
    }

    cat--;
}

long long main()
{
    cin >> n >> k;

    for (long long i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    sort(a, a + n);

    cout << bincut(a, 0, n - 1);
}
