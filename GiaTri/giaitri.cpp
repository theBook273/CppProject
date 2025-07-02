#include<bits/stdc++.h>

using namespace std;

string s;
vector<long long> v;
long long k;

long long main()
{
    cin >> s >> k;

    for(char i : s)
    {
        if('0' <= i && i <= '9')
        {
            v.push_back(i - '0');
        }
    }

    for(long long i = 1; i <= k; i++)
    {
        cout << *max_element(v.begin(),v.end());
    }
}
