#include<bits/stdc++.h>
#define long long long long

using namespace std;

main()
{
    cin.tie(0)->sync_with_stdio(0);
    long long t;
    cin >> t;

    while(t--)
    {
        long long n;
        cin >> n;

        if(n - 1 >= 0) cout << n - 1;
        else cout << 0;

        cout << endl;
    }
}
