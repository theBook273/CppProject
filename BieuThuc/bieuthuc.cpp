#include<bits/stdc++.h>

using namespace std;

long long a[1000000], b[1000000], maxL = -1e9, pos1 = -1, pos2 = -1, tong[2] = {0, 0}, n, maxC = -1e9;

void changetest(long long a[])
{
    for(int i = 0; i < n; i++)
    {
        if((i + 1) % 2 != 0)
        {
            a[i] = -a[i];
        }
    }
}

void change(long long a[])
{
    for(int i = 0; i < n; i++)
    {
        if((i + 1) % 2 == 0)
        {
            a[i] = -a[i];
        }
    }
}

int main()
{
    cin >> n;

    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        b[i] = a[i];
    }

    changetest(a);

    for(int i = 0; i < n; i ++)
    {
        tong[0] += a[i];
    }

    for(int i = 0; i < n; i+=2)
    {
        if(a[i] > maxC)
        {
            maxC = a[i];
            pos1 = i;
        }
    }

    for(int i = 1; i < n; i+=2)
    {
        if(a[i] > maxL)
        {
            maxL = a[i];
            pos2 = i;
        }
    }

    swap(b[pos1], b[pos2]);

    change(b);

    for(int i = 0; i < n; i++)
    {
        cout << b[i] << " ";
    }

    for(int i = 0; i < n; i++)
    {
        tong[1] += b[i];
    }

    cout << *max_element(tong, tong+2);
}
