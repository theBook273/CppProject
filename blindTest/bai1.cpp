#include<bits/stdc++.h>
#define int long long

using namespace std;

main()
{
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;

    while(t--)
    {
        int n;
        cin >> n;

        if(n - 1 >= 0) cout << n - 1;
        else cout << 0;

        cout << endl;
    }
}
