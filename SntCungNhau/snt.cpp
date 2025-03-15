#include<bits/stdc++.h>

using namespace std;

bool a[2000000];
int n;

int main()
{
    memset(a,1,2000000);

    for(int i = 2;i <= 1000012; i++)
    {
        if(a[i] == 1)
        {
            for(int j = 2; j * i < 2000000; j++)
            {
                a[i*j] = 0;
            }
        }
    }

    cin >> n;

    for(int i = n+1; i <= 2000000; i++)
    {
        if(a[i])
        {
            cout << i;
            break;
        }
    }
}
