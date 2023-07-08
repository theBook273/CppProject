#include <bits/stdc++.h>

using namespace std;

long long n, k, a[1000000], cat = 0;

int bincut(long long a[], int l, int r)
{
    int mid = (a[l] + a[r]) / 2;

    cat++;

    if (cat == k)
    {
        return min(mid - a[l], a[r] - mid);
    }

    int mid1, mid2;

    for (int i = 0; i < n; i++)
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

int main()
{
    cin >> n >> k;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    sort(a, a + n);

    cout << bincut(a, 0, n - 1);
}