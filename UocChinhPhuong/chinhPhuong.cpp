#include<bits/stdc++.h>

using namespace std;

bool check[1000000000];
long long a,b,tong = 0;

int main()
{


    cin >> a >> b;

    for(int i = 2; pow(i,2) <= b * 10; i++)
    {
        long long temp = pow(i,2);
        for(int j = 2; j * i <= b * 10; j++)
        {
            check[temp*j] = 1;
        }
    }

    for(int i = a; i <= b; i++)
    {
        for(int j = i + 1; j <= b; j++)
        {
            if(check[i*j])
            {
                tong++;
            }
        }
    }

    cout << tong;
}
