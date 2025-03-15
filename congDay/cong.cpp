#include <bits/stdc++.h>

using namespace std;

long long n, m, a[1000000], b[1000000], tangA[1000000], pos = -1;

void input(long long &temp, long long arr[])
{
    cin >> temp;

    for (int i = 0; i < temp; i++)
    {
        cin >> arr[i];
    }
}

int main()
{
    input(n, a);
    input(m, b);

    for (int i = 0; i < n; i++)
    {
        tangA[i] = 1;
    }

    for (int i = n - 2; i >= 1; i--)
    {
        if (a[i] > a[i - 1])
        {
            tangA[i - 1]++;
        }
    }

    long long maxN = *max_element(tangA, tangA + n);

    for (int i = 0; i < n; i++)
    {
        cout << tangA[i] << " ";
        if (tangA[i] == maxN)
        {
            pos = a[i + maxN];
        }
    }

    for (int i = 1; i < m; i++)
    {
        if (b[i] >= a[i])
        {
            long long temp = 1;
            while (b[i] <= b[i + 1])
            {
                temp++;
                i++;
            }
            cout << pos;
            return 0;
        }
    }
}